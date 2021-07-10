cmake_minimum_required(VERSION 3.19)
project(containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(containers main.cpp Vector.hpp Utils.hpp VectorIterator.hpp)