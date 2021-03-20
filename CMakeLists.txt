cmake_minimum_required(VERSION 3.17)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/LinkedList)
include_directories(include/Nodes)

add_library(linkedlist_library STATIC
        src/LinkedList/LinkedList.cpp)

add_executable(main main.cpp)
find_library(LINKEDLIST_LIBRARY linkedlist_library lib)
target_link_libraries(main LINK_PUBLIC ${LINKEDLIST_LIBRARY})