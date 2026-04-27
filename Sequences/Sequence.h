#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H

template <class T>

class Sequence {
public:
    // получаем что-то
    virtual int GetLength() const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual Sequence<T>* GetSubsequence(int start_index, int end_index) const = 0;

    // добавляем, получаем указатель на элемент/последовательность
    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* InsertAt(int index, T item) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* other) const = 0;

    //функции map-where-reduce
    virtual Sequence<T>* Map(T (*f)(T)) const = 0;
    virtual Sequence<T>* Where(bool (*f)(T)) const = 0;
    virtual T Reduce(T (*f)(T, T), T initial) const = 0;

    //перопределение оператора
    virtual T operator[](int index) const = 0;

    //Деструктор
    virtual ~Sequence() = default;
};

#endif //LAB2_SEQUENCE_H
