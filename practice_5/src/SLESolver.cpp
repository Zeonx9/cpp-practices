//
// Created by musht on 05.11.2022.
//

#include "../include/SLESolver.h"
template class SLESolver<int>;
template class SLESolver<double>;

template<class T>
SLESolver<T>::SLESolver(Matrix<T> &matr, Vector<T> &v) : coefs(matr), col(v) {}

template<class T>
Vector<T> SLESolver<T>::swapColumn(int j, Vector<T> &v) {
    auto out = coefs.column(j);
    for (int i = 0; i < coefs.n(); ++i)
        coefs[i][j] = v[i];
    return out;
}

template<class T>
Vector<double> SLESolver<T>::findSolution() {
    double det = coefs.det();
    std::vector<double> results;
    for (int j = 0; j < coefs.m(); ++j) {
        auto cur = swapColumn(j, col);
        results.push_back((double) coefs.det() / det);
        swapColumn(j, cur);
    }
    return Vector<double>(results);
}
