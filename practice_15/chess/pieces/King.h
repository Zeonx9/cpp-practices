//
// Created by musht on 20.02.2023.
//

#ifndef CPP_TRAININGS_KING_H
#define CPP_TRAININGS_KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color col, int r, int c) : Piece(col, r, c) {
        cell[0][0].set_text_center("Kng", 1);
    }

    bool check_move(vec2 to) override {
        return std::abs(to.first - y) <= 1 and std::abs(to.second - x) <= 1;
    }

    bool check_capture(vec2 to) override {
        return check_move(to);
    }
};


#endif //CPP_TRAININGS_KING_H
