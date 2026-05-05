cmake_minimum_required(VERSION 4.0)
project(lab2 CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab2 main.cpp
        my_except.h
        DynamicArray.h
        LinkedList.h
        Sequences/Sequence.h
        Sequences/ArraySequence.h
        Sequences/ListSequence.h
        Sequences/MutableArraySequence.h
        Sequences/ImmutableArraySequence.h
        Sequences/MutableListSequence.h
        Sequences/ImmutableListSequence.h)

add_executable(lab2_tests
        tests/test.cpp
        tests/testDynamicArray.cpp
        tests/testLinkedList.cpp
        tests/testArraySequence.cpp
        tests/testListSequence.cpp
        my_except.h
        DynamicArray.h
        LinkedList.h
        Sequences/Sequence.h
        Sequences/ArraySequence.h
        Sequences/ListSequence.h
        Sequences/MutableArraySequence.h
        Sequences/ImmutableArraySequence.h
        Sequences/MutableListSequence.h
        Sequences/ImmutableListSequence.h
        tests/testMutable.cpp
        tests/testImmutable.cpp
)

