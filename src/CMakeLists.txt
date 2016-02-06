cmake_minimum_required(VERSION 3.3)

project(cpp-py-ex)

include_directories(.)

add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(types)

set(cpp_py_sources cpppy.m.cpp)

add_executable(cpp-py ${cpp_py_sources})

target_link_libraries(cpp-py lexer parser types)
