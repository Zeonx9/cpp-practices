//
// Created by musht on 13.02.2023.
//

#ifndef CPP_TRAININGS_RECTANGLE_H
#define CPP_TRAININGS_RECTANGLE_H


#include <utility>
#include <iostream>
#include "Shape.h"

class Rectangle : public Shape {
private:
    static int count;
    double width, height;
    Rectangle(int id, double w, double h) : Shape(id), width(w), height(h) {}

public:
    Rectangle(double width, double height) : Rectangle(count, width, height) {
        count += 3;
    }

    double get_width() const {
        return width;
    }
    double get_height() const {
        return height;
    }
    std::pair<double, double> get_sides() const {
        return {width, height};
    }

    double get_area() const override {
        return width * height;
    }

    double get_perimeter() const override {
        return 2 * (width + height);
    }

    void draw(std::ostream &os) const override {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < 2 * width; ++j) {
                os << (char) 178;
            }
            os << '\n';
        }
    }

    static Rectangle* scan() {
        double h, w;
        std::cout << "Enter height and width:\n";
        std::cin >> h >> w;
        return new Rectangle{w, h};
    }
};


#endif //CPP_TRAININGS_RECTANGLE_H
