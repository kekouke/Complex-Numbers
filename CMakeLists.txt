cmake_minimum_required(VERSION 3.17)
project(ClassComplex)

set(CMAKE_CXX_STANDARD 17)

add_executable(ClassComplex main.cpp complex_num.h complex_num.cpp rational.h rational.cpp catch.hpp big_integers.h big_integers.cpp)