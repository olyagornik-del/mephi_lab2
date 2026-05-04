#include <cassert> // assert
#include <cstdio> //printf

#include "testMutable.h"
#include "../Sequences/ArraySequence.h"
#include "../Sequences/ListSequence.h"

void testArraySequenceAppend() {
    ArraySequence<int> Seq;
    Seq.Append(1);
    Seq.Append(2);
    Seq.Append(3);

    assert(Seq.GetLength() == 3);
    assert(Seq.GetFirst() == 1);
    assert(Seq.GetLast() == 3);

    printf("  [OK] testArraySequenceAppend\n");
}

void testArraySequencePrepend() {
    ArraySequence<int> Seq;
    Seq.Prepend(3);
    Seq.Prepend(2);
    Seq.Prepend(1);

    assert(Seq.GetLength() == 3);
    assert(Seq.GetFirst() == 1);
    assert(Seq.GetLast() == 3);

    printf("  [OK] testArraySequencePrepend\n");
}

void testArraySequenceInsertAt() {
    int items[] = {1, 3};
    ArraySequence<int> Seq(items, 2);

    // вставка в середину
    Seq.InsertAt(1, 2);
    assert(Seq.GetLength() == 3);
    assert(Seq.Get(1) == 2);

    // вставка в начало
    Seq.InsertAt(0, 0);
    assert(Seq.GetFirst() == 0);

    // вставка в конец
    Seq.InsertAt(Seq.GetLength(), 99);
    assert(Seq.GetLast() == 99);

    // некорректный индекс
    bool threw = false;
    try { Seq.InsertAt(-1, 0); } catch (const OutOfRange&) { threw = true; }
    assert(threw);

    printf("  [OK] testArraySequenceInsertAt\n");
}

void testListSequenceAppend() {
    ListSequence<int> Seq;
    Seq.Append(1);
    Seq.Append(2);
    Seq.Append(3);

    assert(Seq.GetLength() == 3);
    assert(Seq.GetFirst() == 1);
    assert(Seq.GetLast() == 3);

    printf("  [OK] testListSequenceAppend\n");
}

void testListSequencePrepend() {
    ListSequence<int> Seq;
    Seq.Prepend(3);
    Seq.Prepend(2);
    Seq.Prepend(1);

    assert(Seq.GetLength() == 3);
    assert(Seq.GetFirst() == 1);
    assert(Seq.GetLast() == 3);

    printf("  [OK] testListSequencePrepend\n");
}

void testListSequenceInsertAt() {
    int items[] = {1, 3};
    ListSequence<int> Seq(items, 2);

    // вставка в середину
    Seq.InsertAt(1, 2);
    assert(Seq.GetLength() == 3);
    assert(Seq.Get(1) == 2);

    // вставка в начало
    Seq.InsertAt(0, 0);
    assert(Seq.GetFirst() == 0);

    // вставка в конец
    Seq.InsertAt(Seq.GetLength(), 99);
    assert(Seq.GetLast() == 99);

    // некорректный индекс
    bool threw = false;
    try { Seq.InsertAt(-1, 0); } catch (const OutOfRange&) { threw = true; }
    assert(threw);

    printf("  [OK] testListSequenceInsertAt\n");
}


void testMutableAll() {
    printf("=== Тесты Mutable (List+Array) ===\n");
    testArraySequenceAppend();
    testArraySequencePrepend();
    testArraySequenceInsertAt();
    testListSequenceAppend();
    testListSequencePrepend();
    testListSequenceInsertAt();
    printf("=== Все тесты пройдены! ===\n\n");
}
