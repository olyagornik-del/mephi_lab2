cmake_minimum_required(VERSION 4.0)
project(lab2 CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2
        main.cpp
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
        Sequences/BitSequence.h
        scanValues.h
        menu.h
        SequenceOperations.h)

add_executable(lab2_tests
        tests/test.cpp
        tests/testDynamicArray.cpp
        tests/testLinkedList.cpp
        tests/testArraySequence.cpp
        tests/testListSequence.cpp
        tests/testMutable.cpp
        tests/testImmutable.cpp
        Sequences/BitSequence.h
        tests/testBitSequence.cpp
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
)

