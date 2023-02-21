//
// Created by musht on 13.02.2023.
//

#ifndef CPP_TRAININGS_DRAWABLE2D_H
#define CPP_TRAININGS_DRAWABLE2D_H

#include "ostream"

class Drawable2D {
public:
    // draws anything on the screen
    virtual void draw(std::ostream &os) const = 0;

    // calculates the area that is occupied
    virtual double get_area() const = 0;

    virtual double get_perimeter() const = 0;
};


#endif //CPP_TRAININGS_DRAWABLE2D_H
