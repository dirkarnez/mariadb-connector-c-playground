#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mariadb/mysql.h"

int my_stmt_result(MYSQL *mysql, const char *buff, MYSQL_BIND* bind)
{
  MYSQL_STMT *stmt;
  int        row_count= 0;
  int        rc;

  stmt= mysql_stmt_init(mysql);

  rc = mysql_stmt_prepare(stmt, buff, (unsigned long)strlen(buff));
  // FAIL_IF(rc, mysql_stmt_error(stmt));
  
  mysql_stmt_bind_param(stmt, bind);

  rc = mysql_stmt_execute(stmt);

  // FAIL_IF(rc, mysql_stmt_error(stmt));

  while (mysql_stmt_fetch(stmt) != MYSQL_NO_DATA)
    row_count++;

  mysql_stmt_close(stmt);

  return row_count;
}

int main (int argc, char* argv[])
{
   // docker run --rm -it -p 3306:3306 -e MYSQL_ROOT_PASSWORD=password -e MYSQL_DATABASE=default mariadb
   // Initialize Connection
   MYSQL *conn;
   if (!(conn = mysql_init(0)))
   {
      fprintf(stderr, "unable to initialize connection struct\n");
      exit(1);
   }

   // Connect to the database
   if (!mysql_real_connect(
         conn,                 // Connection
         "localhost",// Host
         "root",            // User account
         "password",   // User password
         "default",               // Default database
         3306,                 // Port number
         NULL,                 // Path to socket file
         0                     // Additional options
      ))
   {
      // Report the failed-connection error & close the handle
      fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
   }


   fprintf(stdout, "It works");
   // stmt = mysql_stmt_init(conn);
   // if (!stmt) {
   //    fprintf(stderr, "Error mysql_stmt_init: %s\n", mysql_error(conn));
   // }
   char query[1024];
   strcpy(query, "SELECT * FROM information_schema.tables WHERE `TABLE_SCHEMA` = ?");

   char data[255];
   strcpy(data, "sys");
   
   MYSQL_BIND my_bind[1];
   memset(my_bind, '\0', sizeof(my_bind));
   
   my_bind[0].buffer_type= MYSQL_TYPE_STRING;
   my_bind[0].buffer= (void *)&data;
   my_bind[0].buffer_length= strlen(data);
   
   // should be 102
   fprintf(stdout, "%d", my_stmt_result(conn, query, my_bind));

//   check_stmt_rc(rc,stmt);

   // Use the Connection
   // ...

   // Close the Connection
   mysql_close(conn);

   return 0;
}
