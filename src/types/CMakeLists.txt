cmake_minimum_required(VERSION 3.3)

project(cpp-py-types)

set(cpp_py_types compoundstatement.cpp
                 expressionstatement.cpp
                 smallstatement.cpp
                 statement.cpp)

add_library(types ${cpp_py_types})

