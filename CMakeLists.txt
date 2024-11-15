cmake_minimum_required(VERSION 3.14)

project("mariadb-connector-c-playground")

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mariadbclient STATIC IMPORTED)

set_property(
  TARGET mariadbclient APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(mariadbclient PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${MARIADB_CLIENT_ROOT}/lib/mariadbclient.a"
)
  
set_target_properties(mariadbclient PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(mariadbclient INTERFACE "${MARIADB_CLIENT_ROOT}/include")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} mariadbclient)
