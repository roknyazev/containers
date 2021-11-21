cmake_minimum_required(VERSION 3.16)
project(containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(containers_map map_test.cpp vector.hpp Utils.hpp VectorIterator.hpp TypeTraits.hpp Vector.ipp stack.hpp AVL.hpp MapIterator.hpp map.hpp main_ft.cpp main_std.cpp)

add_executable(containers_vector vector.hpp Utils.hpp VectorIterator.hpp TypeTraits.hpp Vector.ipp stack.hpp AVL.hpp MapIterator.hpp map.hpp vector_test.cpp )

add_executable(containers_stack vector.hpp Utils.hpp VectorIterator.hpp TypeTraits.hpp Vector.ipp stack.hpp AVL.hpp MapIterator.hpp map.hpp stack_test.cpp)

add_executable(containers_ft vector.hpp Utils.hpp VectorIterator.hpp TypeTraits.hpp Vector.ipp stack.hpp AVL.hpp MapIterator.hpp map.hpp main_ft.cpp)
add_executable(containers_std vector.hpp Utils.hpp VectorIterator.hpp TypeTraits.hpp Vector.ipp stack.hpp AVL.hpp MapIterator.hpp map.hpp main_std.cpp)
