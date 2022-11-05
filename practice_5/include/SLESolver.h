//
// Created by musht on 05.11.2022.
//

#ifndef CPP_TRAININGS_SLESOLVER_H
#define CPP_TRAININGS_SLESOLVER_H

#include "Matrix.h"

template<class T>
class SLESolver {
private:
    Matrix<T> coefs;
    Vector<T> col;

    Vector<T> swapColumn(int j, Vector<T> &v);
public:
    // constructs solver from given coeffitiens and vector-column of right part values
    SLESolver(const Matrix<T> &matr, const Vector<T> &v);

    static SLESolver<T> inputSLE();

    Vector<double> findSolution();
};

#endif //CPP_TRAININGS_SLESOLVER_H
