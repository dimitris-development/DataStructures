cmake_minimum_required(VERSION 3.17)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

macro(package_add_test_with_libraries TESTNAME FILES LIBRARIES TEST_WORKING_DIRECTORY)
    add_executable(${TESTNAME} ${FILES})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIBRARIES})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

include_directories(include)
include_directories(include/Lists/)
include_directories(include/Lists/Nodes)

add_library(datastructures STATIC
        src/Lists/LinkedList.cpp
        include/Lists/LinkedList.h
        include/Lists/Nodes/LinkedListNode.h
        include/Lists/DoublyLinkedList.h
        include/Lists/Nodes/DoublyLinkedListNode.h
        src/Lists/DoublyLinkedList.cpp
        include/Lists/CircularLinkedList.h
        src/Lists/CircularLinkedList.cpp)

add_executable(main main.cpp)

find_library(DATASTRUCTURES datastructures lib)
target_link_libraries(main ${DATASTRUCTURES})

enable_testing()
# Unit Tests
package_add_test_with_libraries(LinkedListTest tests/Functional/Lists/LinkedList.test.cpp ${DATASTRUCTURES} tests/Unit)
