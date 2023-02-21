//
// Created by musht on 20.02.2023.
//

#ifndef CPP_TRAININGS_QUEEN_H
#define CPP_TRAININGS_QUEEN_H


#include "Piece.h"

class Queen : public Piece{
public:
    Queen(Color col, int r, int c) : Piece(col, r, c) {
        cell[0][0].set_text_center("Qwn", 1);
    }

    bool check_move(vec2 to) override {
        return to.first == y or to.second == x or std::abs(to.first - y) == std::abs(to.second - x);
    }

    bool check_capture(vec2 to) override {
        return check_move(to);
    }
};


#endif //CPP_TRAININGS_QUEEN_H
