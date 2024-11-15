cmake_minimum_required(VERSION 3.14)

project("mariadb-connector-c-playground")

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mariadbclient STATIC IMPORTED)

set_property(
  TARGET mariadbclient APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

SET(SYSTEM_LIBS ws2_32 advapi32 kernel32 shlwapi crypt32 secur32 bcrypt)

set_target_properties(mariadbclient PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${MARIADB_CLIENT_ROOT}/lib/mariadb/libmariadbclient.a"
)
  
set_target_properties(mariadbclient PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_link_libraries(mariadbclient INTERFACE "${SYSTEM_LIBS}")

target_include_directories(mariadbclient INTERFACE "${MARIADB_CLIENT_ROOT}/include")

add_executable(${PROJECT_NAME} 
    "src/main.c"
)

target_link_libraries(${PROJECT_NAME} mariadbclient)
