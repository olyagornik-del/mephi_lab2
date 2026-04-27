#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H

#include "../DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> data;
public:
    //конструкторы;
    ArraySequence(): data() {}
    explicit ArraySequence(int size): data(size) {}
    ArraySequence(T *items, int size): data(items, size) {}
    ArraySequence(const DynamicArray<T> &other_arr) : data(other_arr) {}

    //получаем длину
    int GetLength() const override{
        return data.GetSize();
    }
    //получаем первый элемент
    T GetFirst() const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        return data.Get(0);
    }
    //получаем последний
    T GetLast() const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        return data.Get(GetLength()-1);
    }
    // получаем элемент по индексу
    T Get(int index) const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        return data.Get(index);
    }
    // получаем подсписок
    Sequence<T>* GetSubsequence(int start_index, int end_index) const override {
        if (start_index < 0 || start_index > end_index || end_index >= data.GetSize()) {
            throw OutOfRange("Некорректные индексы");
        }
        int sub_size = end_index - start_index +1;
        T *temp = new T[sub_size];
        for (int i=0; i<sub_size; i++) {
            temp[i] = Get(i+start_index);
        }
        Sequence<T> *result = new ArraySequence(temp, sub_size);
        delete[] temp;
        return  result;
    }

    // добавляем в конец
    Sequence<T>* Append(T item) override {
        data.Resize(GetLength()+1);
        data.Set(GetLength() - 1, item);
        return this;
    }
    //добавляем в начало
    Sequence<T>* Prepend(T item) override {
        int size = GetLength();
        data.Resize(size + 1);
        for (int i = size; i > 0; i--)
            data.Set(i, Get(i - 1));
        data.Set(0, item);
        return this;
    }
    //вставить по индексу
    Sequence<T>* InsertAt(int index, T item) override {
        if (index < 0 || index > data.GetSize()) {
            throw OutOfRange("Некорректный индекс");
        }
        if (index == 0) {
            Prepend(item);
            return this;
        }
        if (index==data.GetSize()) {
            Append(item);
            return this;
        }
        int size = GetLength();
        data.Resize(size+1);
        for (int i = size; i > index; i--)
            data.Set(i, Get(i - 1));
        data.Set(index, item);
        return this;
    }
    //склеивание списков
    Sequence<T>* Concat(Sequence<T>* other) const override{
        int new_length = GetLength()+other->GetLength();
        T *temp = new T[new_length]; // можно сразу дм
        for (int i=0; i<new_length; i++) {
            if (i<GetLength()) {
                temp[i] = Get(i);
            }
            else {
                temp[i] = other->Get(i-GetLength());
            }
        }
        Sequence<T>* result = new ArraySequence<T>(temp, new_length);
        delete[] temp;
        return result;
    }
    //map
    Sequence<T>* Map(T (*f)(T)) const override {
        ArraySequence<T>* result = new ArraySequence<T>(GetLength());
        for (int i = 0; i < GetLength(); i++)
            result->data.Set(i, f(Get(i)));
        return result;
    }
    // where
    Sequence<T>* Where(bool (*f)(T)) const override {
        ArraySequence<T>* result = new ArraySequence<T>();
        for (int i = 0; i < GetLength(); i++)
            if (f(Get(i)))
                result->Append(Get(i));
        return result;
    }
    //reduce
    T Reduce(T (*f)(T, T), T initial) const override {
        T result = initial;
        for (int i=0; i<GetLength(); i++) {
            result = f(result, Get(i));
        }
        return result;
    }
    //оператор []
    T operator[](int index) const override {
        return Get(index);
    }



};

#endif //LAB2_ARRAYSEQUENCE_H