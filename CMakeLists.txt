cmake_minimum_required(VERSION 4.0)
project(lab2 CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab2 main.cpp
        DynamicArray.h
        my_stdexcept.h
        LinkedList.h
        Sequences/Sequence.h
        Sequences/ArraySequence.h
        Sequences/ListSequence.h)

add_executable(lab2_tests
        tests/test.cpp
        tests/testDynamicArray.cpp
        tests/testLinkedList.cpp
        tests/testArraySequence.cpp
        DynamicArray.h
        my_stdexcept.h
        LinkedList.h
        Sequences/Sequence.h
        Sequences/ArraySequence.h)

