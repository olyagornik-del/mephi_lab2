#ifndef LAB2_IMMUTABLEARRAYSEQUENCE_H
#define LAB2_IMMUTABLEARRAYSEQUENCE_H

#include "ArraySequence.h"

template <class T>
class ImmutableArraySequence : public ArraySequence<T> {
protected:
    ArraySequence<T>* MakeInstance() override {
        return new ImmutableArraySequence<T>(*this); // копия через copy ctor
    }
public:
    ImmutableArraySequence() : ArraySequence<T>() {}
    ImmutableArraySequence(T* items, int size) : ArraySequence<T>(items, size) {}
    explicit ImmutableArraySequence(int size) : ArraySequence<T>(size) {}
};

#endif //LAB2_IMMUTABLEARRAYSEQUENCE_H