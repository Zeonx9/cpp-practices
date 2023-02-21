//
// Created by musht on 21.02.2023.
//

#ifndef CPP_TRAININGS_MOVE_H
#define CPP_TRAININGS_MOVE_H

#include <string>
#include <iostream>
#include "../util/util.h"

class Move {
private:
    static int letter_to_digit(char c) {
        c = (char) tolower(c);
        if (c < 'a' or c > 'h')
            throw std::invalid_argument("wrong letter in move notation\n");
        return (int) (c - 'a');
    }
    static int convert_digit(char c) {
        if (c < '1' or c > '8')
            throw std::invalid_argument("digit expected in move\n");
        return '8' - c;
    }

protected:
    vec2 from, to;
    Move(int r1, int c1, int r2, int c2) : from{r1, c1}, to{r2, c2} {}

public:
    static Move scan() {
        std::cout << "Enter the move:\n";
        std::string move_string;
        std::getline(std::cin, move_string);
        return {
            convert_digit(move_string[1]), letter_to_digit(move_string[0]),
            convert_digit(move_string[3]), letter_to_digit(move_string[2])
        };
    }

    vec2 const &get_from() const {
        return from;
    }

    vec2 const &get_to() const {
        return to;
    }
};


#endif //CPP_TRAININGS_MOVE_H
