//
// Created by musht on 19.02.2023.
//

#ifndef CPP_TRAININGS_CLASSICBOARD_H
#define CPP_TRAININGS_CLASSICBOARD_H


#include <vector>
#include "Board.h"
#include "../pieces/Pawn.h"
#include "../pieces/Rook.h"
#include "../pieces/Knight.h"
#include "../pieces/Bishop.h"
#include "../pieces/Queen.h"
#include "../pieces/King.h"

class ClassicBoard : public Board {
private:
    const int size = 8;

    void make_header(char fill1, char fill2) {
        cells[0][0].set_fill(fill1);
        for (int i = 0; i < size; ++i) {
            cells[0][i + 1].fill_row(fill2, 1);
            cells[0][i + 1].set_text_center(std::string(1, (char)('A' + i)), 0);
        }
    }

    void make_bar(char fill) {
        for (int i = 1; i < get_size().first; ++i) {
            cells[i][0].set_text_center(std::to_string(9 - i), 1);
            cells[i][0].set_right_fill(fill);
        }
    }

    void make_body() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cells[i + 1][j + 1].set_fill((i + j) % 2 == 0 ? (char) 178 : ' ');
            }
        }
    }

    template<class TPiece>
    void place_black_white_piece_in_col(int r, int c) {
        pieces.push_back(std::make_unique<TPiece>(Piece::Color::White, 7 - r, c));
        pieces.push_back(std::make_unique<TPiece>(Piece::Color::Black, r, c));
    }

    template<class TPiece>
    void place_symmetrically(int r, int c) {
        place_black_white_piece_in_col<TPiece>(r, c);
        place_black_white_piece_in_col<TPiece>(r, 7 - c);
    }

public:
    ClassicBoard() {
        for (int i = 0; i < size + 1; ++i) {
            cells.emplace_back(size + 1, ConsoleCell());
        }
        make_header('#', '_');
        make_bar('|');
        make_body();

        for (int i = 0; i < 8; ++i) {
            place_black_white_piece_in_col<Pawn>(1, i);
        }
        place_symmetrically<Rook>(0, 0);
        place_symmetrically<Knight>(0, 1);
        place_symmetrically<Bishop>(0, 2);
        place_black_white_piece_in_col<King>(0, 3);
        place_black_white_piece_in_col<Queen>(0, 4);
    }

    vec2 get_size() const override {
        return {1 + size, 1 + size};
    }

    vec2 get_coordinates() const override {
        return {1, 1};
    }

    const ConsoleSprite &get_cells() const override {
        return cells;
    }

    void draw_pieces(Renderer &renderer) override {
        for (auto &piece : pieces) {
            renderer.draw(*piece, {2, 2});
        }
    }
};


#endif //CPP_TRAININGS_CLASSICBOARD_H
