//
// Created by musht on 04.11.2022.
//

#include "include/SLESolver.h"

int main() {
    Matrix<int> system{{3, -5}, {2, 7}};
    Vector<int> res{13, 81};
    SLESolver<int> solver(system, res);
    Vector<double> solution = solver.findSolution();
    std::cout << solution;
}