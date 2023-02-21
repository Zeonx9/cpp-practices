//
// Created by musht on 21.02.2023.
//

#ifndef CPP_TRAININGS_PLAYER_H
#define CPP_TRAININGS_PLAYER_H


#include <string>
#include <iostream>
#include "../pieces/Piece.h"

class Player {
protected:
    std::string name = "player";
    Piece::Color color;

public:
    explicit Player(Piece::Color col) : color(col) {}

    Piece::Color get_color() const {
        return color;
    }

    std::string get_name() const {
        return name;
    }

    void set_name(const std::string &str_name) {
        name = str_name;
    }

    void ask_name() {
        std::cout << "Enter name of player:\n";
        std::getline(std::cin, name);
    }
};


#endif //CPP_TRAININGS_PLAYER_H
