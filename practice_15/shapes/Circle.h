//
// Created by musht on 13.02.2023.
//

#ifndef CPP_TRAININGS_CIRCLE_H
#define CPP_TRAININGS_CIRCLE_H

#include "Shape.h"
#include <cmath>
#include <iostream>

class Circle : public Shape {
private:
    static int count;
    double radius;

    Circle(int id, double r) : Shape(id), radius(r) {}

public:
    explicit Circle(double radius) : Circle(count, radius) {
        count += 3;
    }

    double get_radius() const {
        return radius;
    }

    double get_area() const override {
        return radius * radius * M_PI;
    }

    double get_perimeter() const override {
        return M_PI * 2 * radius;
    }

    void draw(std::ostream &os) const override {
        for (int i = 0; i < 2 * radius; ++i) {
            double h = 2 * sqrt(2 * radius * i - i * i);
            for (int j = 0; j < 2 * radius - h; ++j) {
                os << ' ';
            }
            for (int j = 0; j < h * 2; ++j) {
                os << (char) 178;
            }
            os << '\n';
        }
    }

    static Circle* scan() {
        double r;
        std::cout << "Enter radius:\n";
        std::cin >> r;
        return new Circle{r};
    }
};

#endif //CPP_TRAININGS_CIRCLE_H
