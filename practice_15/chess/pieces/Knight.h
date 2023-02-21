//
// Created by musht on 20.02.2023.
//

#ifndef CPP_TRAININGS_KNIGHT_H
#define CPP_TRAININGS_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color col, int r, int c) : Piece(col, r, c) {
        cell[0][0].set_text_center("Nyt", 1);
    }

    bool check_move(vec2 to) override {
        int a = std::abs(to.first - y), b = std::abs(to.second - x);
        return (a == 2 and b == 1) or (a == 1 and b == 2);
    }

    bool check_capture(vec2 to) override {
        return check_move(to);
    }
};


#endif //CPP_TRAININGS_KNIGHT_H
