#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include "my_stdexcept.h"

template <class T>

class DynamicArray {
private:
    T *data;
    size_t size;
    size_t capacity;

public:
    // конструктор по умолчанию
    DynamicArray(): data(nullptr), size(0), capacity(0) {}
    // конструктор куда передаём только размер, заполняем нулями
    explicit DynamicArray(int size): size(size) {
        if (size<0)
            throw InvalidArgument("Нельзя создать массив размером меньше нуля");
        data = new T [size]{};
        capacity = size;
    }
    // конструктор с размером и переданными данными
    DynamicArray(T *items, int size): size(size) {
        if (size<0) {
            throw InvalidArgument("Нельзя создать массив размером меньше нуля");
        }
        data = new T [size]{};
        for (int i=0; i<size; i++) {
            data[i] = items[i];
        }
        capacity = size;
    }
    //копирующий конструктор
    DynamicArray(const DynamicArray<T> &other_arr): size(other_arr.size) {
        data = new T[size]{};
        for (int i=0; i<size; i++) {
            data[i] = other_arr.data[i];
        }
        capacity = size;
    }

    //получаем размер списка
    int GetSize() const {
        return size;
    }
    // достаём элемент по индексу
    T Get(size_t index) const {
        if (index>=size) {
            throw InvalidArgument("Нет такого индекса в вашем списке");
        }
        return data[index];
    }
    //изменить элемент по номеру
    void Set(size_t index, T value) {
        if (index>=size) {
            throw InvalidArgument("Нет такого индекса в вашем списке");
        }
        data[index] = value;
    }
    // изменение размера
    void Resize(size_t new_size) {
        if (new_size>capacity) {
            capacity = (new_size > capacity * 2) ? new_size : capacity * 2;;
            T* new_data = new T [capacity]{};
            for (int i=0; i<size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            size = new_size;
        }
        else {
            size = new_size;
        }
    }

    ~DynamicArray() {
        delete[] data;
    }
};

#endif //LAB2_DYNAMICARRAY_H