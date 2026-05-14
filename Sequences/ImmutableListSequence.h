#ifndef LAB2_IMMUTABLELISTSEQUENCE_H
#define LAB2_IMMUTABLELISTSEQUENCE_H

#include "MutableListSequence.h"

template <class T>
class ImmutableListSequence : public MutableListSequence<T> {
protected:
    MutableListSequence<T>* MakeInstance() override {
        return new ImmutableListSequence<T>(*this);
    }
public:
    ImmutableListSequence(): MutableListSequence<T>() {}
    explicit ImmutableListSequence(int size): MutableListSequence<T>(size) {}
    ImmutableListSequence(T *items, int size): MutableListSequence<T>(items, size) {}
};
#endif //LAB2_IMMUTABLELISTSEQUENCE_H