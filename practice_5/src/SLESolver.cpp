//
// Created by musht on 05.11.2022.
//

#include "../include/SLESolver.h"
template class SLESolver<int>;
template class SLESolver<double>;

template<class T>
SLESolver<T>::SLESolver(const Matrix<T> &matr, const Vector<T> &v) : coefs(matr), col(v) {}

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
    if (det == 0) {
        std::cout << "coeffitients matrix has a zero determinant, roots cannot be found using Cramer's rule!\n";
        return Vector<double>(1);
    }
    std::vector<double> results;
    for (int j = 0; j < coefs.m(); ++j) {
        auto cur = swapColumn(j, col);
        results.push_back((double) coefs.det() / det);
        swapColumn(j, cur);
    }
    return Vector<double>(results);
}

template<class T>
SLESolver<T> SLESolver<T>::inputSLE() {
    int n;
    std::cout   << "Enter number of variables in equation or number of equations in system, they must be equal:\n";
    std::cin >> n;
    std::vector<Vector<T>> system;
    std::vector<T> result(n, 0);
    std::cout << "Enter coefficients separating them with whitespace\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "coeffitients of " << i + 1 << " equation:\n";
        std::vector<T> equation(n, 0);
        for (int j = 0; j < n; ++j) {
            std::cin >> equation[j];
        }
        system.emplace_back(equation);
        std::cout << "enter number after '=':\n";
        std::cin >> result[i];
    }
    return {Matrix(system), Vector(result)};
}
