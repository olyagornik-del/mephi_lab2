#include "testDynamicArray.h"
#include "testLinkedList.h"
#include "testArraySequence.h"
#include "testListSequence.h"
#include "testMutable.h"
#include "testImmutable.h"

int main() {
    testDynamicArrayAll();
    testLinkedListAll();
    testArraySequenceAll();
    testListSequenceAll();
    testMutableAll();
    testImmutableAll();
}
