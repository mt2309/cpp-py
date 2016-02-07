cmake_minimum_required(VERSION 3.3)

project(cpp-py-types)

set(cpp_py_types basictypes.cpp
                 compoundstatement.cpp
                 expressionstatement.cpp
                 operators.cpp
                 smallstatement.cpp
                 statement.cpp)

add_library(types ${cpp_py_types})

