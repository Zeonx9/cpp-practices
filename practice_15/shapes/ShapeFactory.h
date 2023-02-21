//
// Created by musht on 13.02.2023.
//

#ifndef CPP_TRAININGS_SHAPEFACTORY_H
#define CPP_TRAININGS_SHAPEFACTORY_H


#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

class ShapeFactory {
public:
    static Shape* scan() {
        int type;
        std::cout << "enter type: 1 = Rectangle, 2 = Circle, 3 = triangle\n";
        std::cin >> type;
        switch (type) {
            case 1:
                return Rectangle::scan();
            case 2:
                return Circle::scan();
            case 3:
                return Triangle::scan();
            default:
                throw std::invalid_argument("Invalid Shape type");
        }
    }
};


#endif //CPP_TRAININGS_SHAPEFACTORY_H
