cmake_minimum_required(VERSION 3.20)
project(BmiApp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(asio CONFIG REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS net core base)

include(${wxWidgets_USE_FILE})


if(WIN32)
    add_executable(BmiApp WIN32 src/main.cpp)
elseif(APPLE)
    add_executable(BmiApp MACOSX_BUNDLE src/main.cpp)
else()
    # Linux / Unix
    add_executable(BmiApp src/main.cpp)
endif()


if(MSVC)
    add_compile_options(/MP /W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -O2)
endif()


target_link_libraries(BmiApp PRIVATE 
    asio::asio 
    ${wxWidgets_LIBRARIES}
)