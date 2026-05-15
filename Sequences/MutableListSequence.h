
#ifndef LAB2_MUTABLELISTSEQUENCE_H
#define LAB2_MUTABLELISTSEQUENCE_H

#include "../LinkedList.h"
#include "Sequence.h"

template <class T>
class MutableListSequence : public Sequence<T> {
private:
    LinkedList<T> data;
protected:
    virtual MutableListSequence<T>* MakeInstance() { return this; }
    Sequence<T>* Instance() const override { return new MutableListSequence<T>(); }
    void AppendInPlace(const T& item) override { data.Append(item); }
public:
    //конструкторы
    MutableListSequence(): data() {}
    MutableListSequence(T *items, int size ): data(items, size) {}
    explicit MutableListSequence (const LinkedList<T> &other_list): data(other_list) {}

    //получаем длину
    int GetLength() const override {
        return data.GetLength();
    }
    // получаем элемент по индексу
    T Get(int index) const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        if (index < 0 || index >= GetLength())
            throw OutOfRange("index", index, 0, GetLength() - 1);
        return data.Get(index);
    }

    //добавляем в конец
    Sequence<T>* Append(const T &item) override {
        MutableListSequence<T> *result = MakeInstance();
        result->data.Append(item);
        return result;
    }
    //добавляем в начало
    Sequence<T>* Prepend(const T &item) override {
        MutableListSequence<T> *result = MakeInstance();
        result->data.Prepend(item);
        return result;
    }
    //вставить по индексу
    Sequence<T>* InsertAt(int index, const T &item) override {
        if (index < 0 || index > GetLength()) {
            throw OutOfRange("index", index, 0, GetLength());
        }
        MutableListSequence<T> *result = MakeInstance();
        result->data.InsertAt(index, item);
        return result;
    }

};

#endif //LAB2_MUTABLELISTSEQUENCE_H