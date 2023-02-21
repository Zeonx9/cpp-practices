//
// Created by musht on 19.02.2023.
//

#ifndef CPP_TRAININGS_BOARD_H
#define CPP_TRAININGS_BOARD_H


#include "../render/console/ConsoleDrawable.h"
#include "../pieces/Piece.h"
#include "../util/util.h"
#include "../move/Move.h"
#include "../move/Player.h"
#include "../pieces/King.h"

class Board : public ConsoleDrawable {
private:
    Piece &findByPos(vec2 pos) {
        for (auto &piece : pieces) {
            if (piece->get_coordinates() == pos)
                return *piece;
        }
        throw std::invalid_argument("no piece at given position");
    }

    bool check_empty(vec2 pos) {
        for (auto &piece : pieces) {
            if (piece->get_coordinates() == pos)
                return false;
        }
        return true;
    }

    void remove(vec2 pos) {
        for (auto iter = pieces.begin(); iter < pieces.end(); ++iter) {
            if ((*iter)->get_coordinates() == pos) {
                pieces.erase(iter);
                return;
            }
        }
    }

protected:
    std::vector<std::unique_ptr<Piece>> pieces;
    ConsoleSprite cells;

public:
    virtual void draw_pieces(Renderer &renderer) = 0;

    void make_move(const Move &move, const Player &player) {
        Piece &piece = findByPos(move.get_from());
        if (piece.get_color() != player.get_color()) {
            throw std::invalid_argument("it is not your piece");
        }

        // capture or just move (only necessary checks)
        if (!check_empty(move.get_to())) {
            const Piece &target = findByPos(move.get_to());

            if (!piece.check_capture(move.get_to())) {
                throw std::invalid_argument("piece does not capture that way");
            }

            if (target.get_color() == player.get_color()) {
                throw std::invalid_argument("cannot capture your own piece");
            }

            // remove the piece that has been captured
            remove(move.get_to());
        } else {
            if (!piece.check_move(move.get_to())) {
                throw std::invalid_argument("piece does not move that way");
            }
        }
        piece.set_position(move.get_to());
    }

    bool has_king(Piece::Color color) {
        for (auto &piece : pieces) {
            try {
                dynamic_cast<King&>(*piece);
                if (piece->get_color() == color)
                    return true;
            }
            catch (std::bad_cast &e) {}
        }
        return false;
    }

    virtual ~Board() {
        std::cout << "Board erased\n";
    }
};


#endif //CPP_TRAININGS_BOARD_H
