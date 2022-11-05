//
// Created by musht on 04.11.2022.
//

#include "include/SLESolver.h"

int main() {
    auto solver = SLESolver<int>::inputSLE();
    auto solution = solver.findSolution();
    std::cout << solution;
}