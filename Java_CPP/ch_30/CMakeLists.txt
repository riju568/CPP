cmake_minimum_required(VERSION 3.20)
project(Exercise30_02 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

if(WIN32)
    add_executable(Exercise30_02 WIN32 src/main.cpp)
elseif(APPLE)
    add_executable(Exercise30_02 MACOSX_BUNDLE src/main.cpp)
else()
    add_executable(Exercise30_02 src/main.cpp)
endif()

target_link_libraries(Exercise30_02 PRIVATE ${wxWidgets_LIBRARIES})