cmake_minimum_required(VERSION 3.21)
project(dsa VERSION 0.1 LANGUAGES CXX)

find_package(fmt)

set(CMAKE_CXX_STANDARD 23 REQUIRED TRUE)
set(CMAKE_CXX_FLAGS_DEBUG          " ${CMAKE_CXX_FLAGS_INIT} -g -DDEBUG -std=c++23")
set(CMAKE_CXX_FLAGS_MINSIZEREL     " ${CMAKE_CXX_FLAGS_INIT} -Os -DNDEBUG -s")
set(CMAKE_CXX_FLAGS_RELEASE        " ${CMAKE_CXX_FLAGS_INIT} -O2 -DNDEBUG -s -flto -fno-fat-lto-objects")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO " ${CMAKE_CXX_FLAGS_INIT} -O2 -g -DDEBUG")

add_executable(dsa
    src/main.cpp
    src/common.cpp
    src/fibonacci.cpp
    src/arrays/bubble_sort.cpp
    src/arrays/quick_sort.cpp
)

target_link_options(dsa PRIVATE -static-libgcc -static-libstdc++)
target_link_libraries(dsa PRIVATE fmt::fmt)