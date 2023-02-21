//
// Created by musht on 20.02.2023.
//

#ifndef CPP_TRAININGS_BISHOP_H
#define CPP_TRAININGS_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color col, int r, int c) : Piece(col, r, c) {
        cell[0][0].set_text_center("Bsp", 1);
    }

    bool check_move(vec2 to) override {
        return std::abs(to.first - y) == std::abs(to.second - x);
    }

    bool check_capture(vec2 to) override {
        return check_move(to);
    }
};


#endif //CPP_TRAININGS_BISHOP_H
