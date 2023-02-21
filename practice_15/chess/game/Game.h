//
// Created by musht on 19.02.2023.
//

#ifndef CPP_TRAININGS_GAME_H
#define CPP_TRAININGS_GAME_H

#include "../render/Renderer.h"
#include "../board/Board.h"

class Game {
protected:
    std::shared_ptr<Renderer> renderer;
    std::unique_ptr<Board> board;
    std::array<Player, 2> players {Player(Piece::Color::White), Player(Piece::Color::Black)};
    bool game_ended = false;
    int current = 0;

    void draw() {
        renderer->clear();
        renderer->draw(*board);
        board->draw_pieces(*renderer);
        renderer->show();
    }

    void switch_players() {
        current = 1 - current;
    }

    // the repeated logic for every move until game is ended
    virtual void routine() = 0;

public:
    explicit Game(const std::shared_ptr<Renderer> &render) : renderer(render) {
        players[0].ask_name();
        players[1].ask_name();
    }

    void start() {
        draw();
        while (!game_ended) {
            try {
                routine();
            } catch (std::exception &e) {
                std::cout << "something went wrong :(\n";
            }
        }
    }

    // destructor
    virtual ~Game() {
        std::cout << "Game ended\n";
    }
};


#endif //CPP_TRAININGS_GAME_H
