mariadb-connector-c-playground
==============================
### Docker for testing
- `docker run --rm -it -p 3306:3306 -e MYSQL_ROOT_PASSWORD=password -e MYSQL_DATABASE=default mariadb`

### Notes
- > C applications developed using MariaDB Connector/C must include the mysql.h header file.
  - [Application Development with MariaDB Connector/C — MariaDB Documentation](https://mariadb.com/docs/server/connect/programming-languages/c/development/)

### Tutorials
- https://github.com/pingcap/mydumper/blob/0042e179b74fd9cd731be4550bee4c284c212be6/mydumper.c#L1777

### Using
- [dirkarnez/mariadb-connector-c-prebuilt](https://github.com/dirkarnez/mariadb-connector-c-prebuilt)
