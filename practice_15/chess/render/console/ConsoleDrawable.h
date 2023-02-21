//
// Created by musht on 18.02.2023.
//

#ifndef CPP_TRAININGS_CONSOLEDRAWABLE_H
#define CPP_TRAININGS_CONSOLEDRAWABLE_H


#include <utility>
#include "../Renderer.h"
#include "ConsoleCell.h"

class ConsoleDrawable {
public:
    using ConsoleSprite = std::vector<std::vector<ConsoleCell>>;
    // static method that define the size of a cell in numbers of rows and columns (chars)
    // return a pair first vertical size (in cells), then horizontal size (in cells)
    virtual vec2 get_size() const = 0;
    // return coordinates (in cells) first is number of row (from zero) then number of column
    virtual vec2 get_coordinates() const = 0;
    // return a (width * height) * (cell_w * cell_h) chars that represent a drawable
    virtual const ConsoleSprite &get_cells() const = 0;
};


#endif //CPP_TRAININGS_CONSOLEDRAWABLE_H
