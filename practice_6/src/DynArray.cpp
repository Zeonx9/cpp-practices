//
// Created by musht on 06.11.2022.
//

#include <iostream>
#include "../include/DynArray.h"

template class DynArray<int>;
template class DynArray<double>;
template class DynArray<char>;
template class DynArray<std::string>;

template<class T>
DynArray<T>::DynArray(int capacity) {
    values.reserve(capacity);
    ++obj_count;
}

template<class T>
DynArray<T>::DynArray(std::initializer_list<T> li) : values(li) { ++obj_count; }

template<class T>
DynArray<T>::~DynArray() { --obj_count; }

template<class T>
T &DynArray<T>::operator[](int index) {
    if (index < -size() or index >= size()) {
        std::cerr << "index out of range\n";
        exit(56);
    }
    index = (index + values.size()) % values.size();
    return values[index];
}

template<class T>
void DynArray<T>::append(T value) {
    values.push_back(value);
}

template<class T>
int DynArray<T>::size() const {
    return values.size();
}

template<class T>
int DynArray<T>::getObjectCount() {
    return obj_count;
}

template<class T>
DynArray<T> &DynArray<T>::operator+=(const DynArray<T> &other) {
    values.insert(values.end(), other.values.begin(), other.values.end());
    return *this;
}

template<class T>
DynArray<T> DynArray<T>::operator+(const DynArray<T> &other) {
    DynArray<T> res(size() + other.size());
    res += *this;
    res += other;
    return res;
}

template<class T>
DynArray<T> DynArray<T>::operator*(int k) {
    DynArray<T> res(k * size());
    for (int i = 0; i < k; ++i) {
        res += *this;
    }
    return res;
}

template<class T>
DynArray<T> &DynArray<T>::operator=(const DynArray &other) {
    this->values = other.values;
    return *this;
}

template<class T>
DynArray<T>::DynArray(const DynArray<T> &array) {
    this->values = array.values;
    ++obj_count;
}

