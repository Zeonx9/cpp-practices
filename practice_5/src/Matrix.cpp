//
// Created by musht on 04.11.2022.
//

#include "../include/Matrix.h"
template class Matrix<int>;
template class Matrix<double>;

template<class T>
void Matrix<T>::checkSize(const Matrix<T> &m, const std::string &action) {
    if (m.n() != n() or m.m() != this->m()) {
        std::cerr << "cannot " + action + " matrices with not mathcing dimensions\n";
        exit(-32);
    }
}

template<class T>
int Matrix<T>::n() const {
    return values.size();
}

template<class T>
int Matrix<T>::m() const {
    return values[0].n();
}

template<class T>
Matrix<T>::Matrix(int n, int m) {
    if (n < 1 or m < 1) {
        std::cerr << "dimensions of matrix cannot be less than 1\n";
        exit(-31);
    }
    values = std::vector<Vector<T>>(n, Vector<T>(m));
}

template<class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> li) {
    for (const auto &row : li) {
        values.emplace_back(row);
    }
}

template<class T>
Matrix<T>::Matrix(const std::vector<Vector<T>> &rows) : values(rows) {}

template<class T>
Vector<T> &Matrix<T>::operator[](int i) {
    if (i < 0 or i >= n()) {
        std::cerr << "row index out of range\n";
        exit(-33);
    }
    return values[i];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) {
    checkSize(m, "add");
    std::vector<Vector<T>> r_vec;
    for (int i = 0; i < n(); ++i){
        r_vec.push_back(values[i] + m.values[i]);
    }
    return Matrix<T>(r_vec);
}

template<class T>
Matrix<T> Matrix<T>::operator*(double k) {
    std::vector<Vector<T>> r_vec;
    for (auto &row : values) {
        r_vec.push_back(row * k);
    }
    return Matrix<T>(r_vec);
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &m) {
    if (this->m() != m.n() or n() != m.m()) {
        std::cerr << "cannot multiply such matices\n";
        exit(-35);
    }
    std::vector<Vector<T>> res;
    auto mt = m.transp();
    for (auto &r : values) {
        std::vector<T> res_row;
        for (auto &c : mt.values)
            res_row.push_back(r * c);
        res.emplace_back(res_row);
    }
    return Matrix<T>(res);
}

template<class T>
Vector<T> Matrix<T>::operator*(Vector<T> &v) {
    std::vector<T> res;
    for (auto & row : values) {
        res.push_back(row * v);
    }
    return Vector<T>(res);
}


template<class T>
Vector<T> Matrix<T>::column(int i) {
    if (i < 0 or i >= m()) {
        std::cerr << "column index out of range\n";
        exit(-34);
    }
    std::vector<T> c;
    for (int j = 0; j < n(); ++j)
        c.push_back(values[j][i]);
    return Vector(c);
}

template<class T>
Matrix<T> Matrix<T>::transp() {
    std::vector<Vector<T>> columns;
    for (int i = 0; i < m(); ++i)
        columns.push_back(column(i));
    return Matrix<T>(columns);
}

template<class T>
Matrix<T> Matrix<T>::minor(int i, int j) {
    std::vector<Vector<T>> minr;
    for(int r = 0; r < n(); ++r) {
        if (r == i) continue;
        std::vector<T> row;
        for(int c = 0; c < m(); ++c) {
            if (c == j) continue;
            row.push_back(values[r][c]);
        }
        minr.emplace_back(row);
    }
    return Matrix<T>(minr);
}

template<class T>
T Matrix<T>::det() {
    if (n() != m()) {
        std::cerr << "determinant can be calculated only for quadratic matices\n";
        exit(-35);
    }
    if (n() == 1)
        return values[0][0];
    if (n() == 2)
        return values[0][0] * values[1][1] - values[0][1] * values[1][0];

    T sum = 0;
    for (int j = 0; j < n(); ++j) {
        sum += (1 - (j % 2) * 2) * values[0][j] * minor(0, j).det();
    }
    return sum;
}

template<class T>
Matrix<double> Matrix<T>::invert() {
    double inv_det = 1 / (double) det();
    std::vector<Vector<double>> res;
    for (int i = 0; i < n(); ++i) {
        std::vector<double> row;
        for (int j = 0; j < m(); ++j) {
            row.push_back((1 - 2 * ((i + j) % 2)) * minor(i, j).det());
        }
        res.emplace_back(row);
    }
    return Matrix<double>(res).transp() * inv_det;
}
