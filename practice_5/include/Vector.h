//
// Created by musht on 04.11.2022.
//

#ifndef CPP_TRAININGS_VECTOR_H
#define CPP_TRAININGS_VECTOR_H

#include <vector>
#include <iostream>

// represents a vector of given length (n-dimensional)
template <class T>
class Vector {

private:
    std::vector<T> values;

    // called to check if two given vectors has the same size if it is nessecary,
    // exits with code -12 in case of different lengths of vectors
    void checkSize(const Vector<T> &v, const std::string& action);

public:
    // constructs a vector with length = n, all values are set to 0;
    explicit Vector(int n);
    // constructs a vector from list initializer
    Vector(std::initializer_list<T> li);
    //constructs a vector from std::vector
    explicit Vector(std::vector<T> &v);

    // returns the length of vector (dimensions)
    int n() const;

    // subscription operator
    T& operator[](int i);

    // adds two vectors
    Vector<T> operator+(const Vector<T> &v);

    // multiply vecor by scalar
    Vector<T> operator*(double k);

    // multiply vecor by scalar
    template<class V>
    friend Vector<V> operator*(double k, Vector<V> &v);

    // returns dot product of two vectors
    T operator*(const Vector<T> &v);

    // insert string representation of vector v ot ouputs stream os
    template<class V>
    friend std::ostream &operator<<(std::ostream &os, const Vector<V> &v);
};

template<class T>
Vector<T> operator*(double k, Vector<T> &v) {
    return v * k;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &v) {
    os << "(" << v.values[0];
    for (int i = 1; i < v.n(); ++i)
        os << ", " << v.values[i];
    os << ")";
    return os;
}

#endif //CPP_TRAININGS_VECTOR_H
