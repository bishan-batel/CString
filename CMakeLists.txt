cmake_minimum_required(VERSION 3.28)
project(CString)

set(CMAKE_CXX_STANDARD 20)

include_directories(".")

add_executable(CString
        "examples/c_string/test.cpp"
        "examples/c_string/c_string.cpp"
        "examples/c_string/c_string.hpp"
        "utils.hpp"
        main.cpp
        Tests.hpp
)
