//
// Created by musht on 07.11.2022.
//

#include "../include/Queue.h"
template class Queue<int>;

template<class T>
Queue<T>::Queue(int capacity) {
    values.reserve(capacity);
}

template<class T>
void Queue<T>::enqueue(T value) {
    values.push_back(value);
}

template<class T>
T Queue<T>::dequeue() {
    auto res = values[0];
    values.erase(values.begin());
    return res;
}

template<class T>
int Queue<T>::size() const {
    return values.size();
}

template<class T>
Queue<T>::Queue(std::initializer_list<T> li) : values(li) {}

template<class T>
bool Queue<T>::isEmpty() const {
    return size() < 1;
}

