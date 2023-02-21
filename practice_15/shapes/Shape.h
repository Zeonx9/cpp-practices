//
// Created by musht on 13.02.2023.
//

#ifndef CPP_TRAININGS_SHAPE_H
#define CPP_TRAININGS_SHAPE_H


#include "interfaces/Drawable2D.h"

class Shape : public Drawable2D {
protected:
    int _id;
public:
    int get_id() const  {
        return _id;
    }
    explicit Shape(int id) {
        _id = id;
    }
};


#endif //CPP_TRAININGS_SHAPE_H
