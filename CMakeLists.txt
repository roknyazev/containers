cmake_minimum_required(VERSION 3.19)
project(containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(containers main.cpp List.hpp ListIterator.hpp ConstListIterator.hpp ReverseListIterator.hpp ConstReverseListIterator.hpp Node.hpp Vector.hpp)