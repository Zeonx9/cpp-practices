//
// Created by musht on 19.02.2023.
//

#ifndef CPP_TRAININGS_CLASSICGAME_H
#define CPP_TRAININGS_CLASSICGAME_H


#include <iostream>
#include "Game.h"
#include "../board/ClassicBoard.h"
#include "../move/Move.h"
#include "../move/Player.h"

class ClassicGame : public Game {
private:
    void make_move_handle_errors() {
        while (true) {
            try {
                std::cout << players[current].get_name() << "\n";
                Move m = Move::scan();
                board->make_move(m, players[current]);
                return;
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << "\n";
                std::cout << "try again\n";
            }
        }
    }

    void check_game_end() {
        game_ended = !board->has_king(players[current].get_color());
    }

protected:
    void routine() override {
        make_move_handle_errors();
        draw();
        switch_players();
        check_game_end();
    }

public:
    explicit ClassicGame(const std::shared_ptr<Renderer> &render) : Game(render) {
        board = std::make_unique<ClassicBoard>();
    }
};



#endif //CPP_TRAININGS_CLASSICGAME_H
