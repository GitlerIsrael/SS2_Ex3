cmake_minimum_required(VERSION 3.25)
project(Fraction_a)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fraction_a main.cpp sources/Fraction.hpp sources/Fraction.cpp Test.cpp)
