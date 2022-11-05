//
// Created by musht on 04.11.2022.
//

#include "include/Matrix.h"
int main() {
    Matrix<double> m{{1, 15}, {3, 1}};
    std::cout   << m << "\n"
                << m.invert() << "\n"
                << m.invert() * m << "\n";

}