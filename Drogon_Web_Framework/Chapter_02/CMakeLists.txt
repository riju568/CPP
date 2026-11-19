cmake_minimum_required(VERSION 3.10)
project(my_drogon_app CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Drogon CONFIG REQUIRED)

add_executable(my_drogon_app main.cpp)
target_link_libraries(my_drogon_app PRIVATE Drogon::Drogon)