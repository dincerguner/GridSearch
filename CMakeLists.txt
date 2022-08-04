cmake_minimum_required(VERSION 3.18)

project(grid_search)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
if(COMPILER_SUPPORTS_CXX17)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
    message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER} has no C++17 support.")
endif()


set(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext/json)
set(GRIDSEARCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/gridsearch)


add_subdirectory(src/gridsearch)
add_subdirectory(test/gridsearch)
