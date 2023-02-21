//
// Created by musht on 13.02.2023.
//

#ifndef CPP_TRAININGS_TRIANGLE_H
#define CPP_TRAININGS_TRIANGLE_H


#include <array>
#include "Shape.h"
#include <cmath>
#include <iostream>

class Triangle : public Shape{
private:
    static int count;
    std::array<std::pair<double, double>, 3> points;

    Triangle(int id, const std::array<std::pair<double, double>, 3> &p) : Shape(id), points(p) {}

    double get_side(int i, int j) const {
        return hypot(points[i].first - points[j].first, points[i].second - points[j].second);
    }

public:
    explicit Triangle(const std::array<std::pair<double, double>, 3> &points) : Triangle(count, points) {
        count += 3;
    }

    std::pair<double, double> get_point(int index) const {
        return points[index];
    }

    double get_area() const override {
        double p = get_perimeter() / 2;
        return sqrt(p * (p - get_side(0, 1)) * (p - get_side(2, 1)) * (p - get_side(0, 2)));
    }

    double get_perimeter() const override {
        return get_side(0, 1) + get_side(1, 2) + get_side(2, 0);
    }

    void draw(std::ostream &os) const override {
        os << "Triangle " << get_id();
    }

    static Triangle* scan() {
        double x1, y1, x2, y2, x3, y3;
        std::cout << "Enter coordinates of 3 points (first x, then y) on separate lines:\n";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        return new Triangle(std::array<std::pair<double, double>, 3>{
                std::make_pair(x1, y1),
                std::make_pair(x2, y2),
                std::make_pair(x3, y3)
        });
    }
};


#endif //CPP_TRAININGS_TRIANGLE_H
