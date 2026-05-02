
#ifndef LAB2_LISTSEQUENCE_H
#define LAB2_LISTSEQUENCE_H

#include "../LinkedList.h"
#include "Sequence.h"

template <class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> data;
public:
    //конструкторы
    ListSequence(): data() {}
    ListSequence(T *items, int size ): data(items, size) {}
    explicit ListSequence (const LinkedList<T> &other_list): data(other_list) {}

    //получаем длину
    int GetLength() const override {
        return data.GetLength();
    }

    //получаем первый элемент
    T GetFirst() const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        return data.Get(0);
    }//!!
    //получаем последний
    T GetLast() const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        return data.Get(GetLength()-1);
    }//!!
    // получаем элемент по индексу
    T Get(int index) const override {
        if (GetLength() == 0)
            throw OutOfRange("Последовательность пуста");
        if (index < 0 || index >= GetLength())
            throw OutOfRange("index", index, 0, GetLength() - 1);
        return data.Get(index);
    }
    //получаем подсписок
    Sequence<T>* GetSubsequence(int start_index, int end_index) const override {
        if (start_index < 0 || start_index > end_index || end_index >= GetLength()) {
            throw OutOfRange("неверные индексы start_index, end_index");
        }
        LinkedList<T> *sub = data.GetSubList(start_index, end_index);
        Sequence<T> *result = new ListSequence<T>(*sub);
        delete sub;
        return result;
    }

    //добавляем в конец
    Sequence<T>* Append(T item) override {
        data.Append(item);
        return this;
    }
    //добавляем в начало
    Sequence<T>* Prepend(T item) override {
        data.Prepend(item);
        return this;
    }
    //вставить по индексу
    Sequence<T>* InsertAt(int index, T item)override {
        if (index < 0 || index > GetLength()) {
            throw OutOfRange("index", index, 0, GetLength());
        }
        data.InsertAt(index, item);
        return this;
    }
    // склеивание списков
    Sequence<T>* Concat(Sequence<T>* other) const override {
        if (other == nullptr)
            throw InvalidArgument("other");
        LinkedList<T> other_list;
        for (int i = 0; i < other->GetLength(); i++)
            other_list.Append(other->Get(i));
        LinkedList<T>* temp = data.Concat(&other_list);
        Sequence<T>* result = new ListSequence<T>(*temp);
        delete temp;
        return result;
    }

    //map
    Sequence<T>* Map(T (*f)(T)) const override {
        ListSequence<T>* result = new ListSequence<T>();
        for (int i = 0; i < GetLength(); i++)
            result->Append(f(Get(i)));
        return result;
    }
    //where
    Sequence<T>* Where(bool (*f)(T)) const override {
        ListSequence<T>* result = new ListSequence<T>();
        for (int i = 0; i <GetLength(); i++)
            if (f(Get(i))) {
                result->Append(Get(i));
            }
        return result;
    }
    //reduce
    T Reduce(T (*f)(T, T), T initial) const override {
        T result = initial;
        for (int i = 0; i < GetLength(); i++)
            result = f(result, Get(i));
        return result;
    } //!!
    //оператор []
    T operator[](int index) const override {
        return Get(index);
    } //!!
};

#endif //LAB2_LISTSEQUENCE_H