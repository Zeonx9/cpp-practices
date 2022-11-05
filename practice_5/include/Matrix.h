//
// Created by musht on 04.11.2022.
//

#ifndef CPP_TRAININGS_MATRIX_H
#define CPP_TRAININGS_MATRIX_H

#include "Vector.h"

// represents 2-dimensional matrix
template<class T>
class Matrix {
private:
    std::vector<Vector<T>> values;

    // checks sizes of matrices in case of not matching exits with code -32;
    void checkSize(const Matrix<T> &m, const std::string &action);

public:
    // constructs n * m matrix of zeros
    Matrix(int n, int m);
    // constructs matrix from initializer list of vectors
    Matrix(std::initializer_list<std::initializer_list<T>> li);
    // constructs matrix with given rows
    explicit Matrix(const std::vector<Vector<T>> &rows);

    // get the number of row in matrix
    int n() const;
    // get the number of columns in matrix
    int m() const;

    // subscription operator
    Vector<T> &operator[](int i);

    // adds to matrices together
    Matrix<T> operator+(const Matrix<T> &m);

    // multiplies matrix on number;
    Matrix<T> operator*(double k);

    // multiplies matrix by number
    template<class V>
    friend Matrix<V> operator*(double k, Matrix<V> &m);

    // multiplies two matirices;
    Matrix<T> operator*(Matrix<T> &m);

    // multipliess matrix by vector (column)
    Vector<T> operator*(Vector<T> &v);

    //multiplies vector (row) by matix
    template<class V>
    friend Vector<V> operator*(Vector<V> &v, Matrix<V> &m);

    // returns column in the matrix at index = i
    Vector<T> column(int i);

    // transpose the matrix
    Matrix<T> transp();

    // get minor of mitrix associated with element in row i and column j
    Matrix<T> minor(int i, int j);

    // calculate determinant of squared matrix
    T det();

    // returns an iverted matrix to given
    Matrix<double> invert();

    // inserts string representation to the output stream
    template<class V>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<V> &m);
};

template<class T>
Matrix<T> operator*(double k, Matrix<T> &m) {
    return m * k;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &m) {
    os << "[" << m.values[0];
    for (int i = 1; i < m.n(); ++i)
        os << ", " << m.values[i];
    os << "]";
    return os;
}

template<class T>
Vector<T> operator*(Vector<T> &v, Matrix<T> &m) {
    std::vector<T> res;
    auto mt = m.transp();
    for (auto &col : mt.values) {
        res.push_back(v * col);
    }
    return Vector<T>(res);
}

#endif //CPP_TRAININGS_MATRIX_H
