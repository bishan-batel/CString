cmake_minimum_required(VERSION 3.28)
project(CString)

set(CMAKE_CXX_STANDARD 20)

add_executable(CString main.cpp
        c_string.cpp
        c_string.hpp
        utils.hpp)
