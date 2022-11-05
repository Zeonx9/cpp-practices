//
// Created by musht on 04.11.2022.
//

#include "../include/Vector.h"
template class Vector<int>;
template class Vector<double>;

template<class T>
void Vector<T>::checkSize(const Vector<T> &v, const std::string &action) {
    if (n() != v.n()) {
        std::cerr << "Cannot " << action << " vectors of different size\n";
        exit(-12);
    }
}

template<class T>
Vector<T>::Vector(int n) {
    if (n < 1) {
        std::cerr << "cannot create vector with length less than 1\n";
        exit(-13);
    }
    values = std::vector<T>(n, (T) 0);
}

template<class T>
Vector<T>::Vector(std::initializer_list<T> li) : values(li.begin(), li.end()) {}

template<class T>
Vector<T>::Vector(std::vector<T> &v) : values(v) {}

template<class T>
int Vector<T>::n() const { return values.size(); }

template<class T>
Vector<T> Vector<T>::operator+(const Vector<T> &v) {
    checkSize(v, "add");
    Vector<T> r(v);
    for (int i = 0; i < n(); ++i)
        r.values[i] += this->values[i];
    return r;
}

template<class T>
Vector<T> Vector<T>::operator*(double k) {
    Vector<T> r(*this);
    for (int i = 0; i < r.n(); ++i) {
        r.values[i] *= k;
    }
    return r;
}

template<class T>
T Vector<T>::operator*(const Vector<T> &v) {
    checkSize(v, "get dot product of");
    T sum = 0;
    for (int i = 0; i < n(); ++i)
        sum += values[i] * v.values[i];
    return sum;
}

template<class T>
T& Vector<T>::operator[](int i) {
    if (i >= 0 and i < n())
        return values[i];
    std::cerr << "vector index out of range\n";
    exit(-14);
}


