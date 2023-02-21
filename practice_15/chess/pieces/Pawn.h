//
// Created by musht on 20.02.2023.
//

#ifndef CPP_TRAININGS_PAWN_H
#define CPP_TRAININGS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color col, int r, int c) : Piece(col, r, c) {
        cell[0][0].set_text_center("Paw", 1);
    }

    bool check_move(vec2 to) override {
        bool cond = to.second == x;
        if (color == Color::White) {
            return cond and ((y == 6 and to.first == 4) or to.first - y == -1);
        } else {
            return cond and ((y == 1 and to.first == 3) or to.first - y == 1);
        }
    }

    bool check_capture(vec2 to) override {
        bool cond =  std::abs(to.second - x) == 1;
        if (color == Color::White) {
            return cond and to.first - y == -1;
        } else {
            return cond and to.first - y == 1;
        }
    }
};


#endif //CPP_TRAININGS_PAWN_H
