//
// Created by musht on 18.02.2023.
//

#ifndef CPP_TRAININGS_PIECE_H
#define CPP_TRAININGS_PIECE_H

// base class for all chess pieces
class Piece : public ConsoleDrawable {
public:
    // represents a color of a piece
    enum class Color : char {
        White = 'W', Black = 'B'
    };

protected:
    ConsoleSprite cell;
    int x, y;
    Color color;

public:
    Piece(Color col, int r, int c) : color(col), x(c), y(r) {
       cell =  ConsoleSprite(1, std::vector<ConsoleCell>(1, ConsoleCell(' ')));
       cell[0][0].set_text_center(std::string(1, static_cast<char>(get_color())), 0);
    };

    Color get_color() const {
        return color;
    }
    vec2 get_size() const override {
        return {1, 1};
    }
    vec2 get_coordinates() const override {
        return {y, x};
    }

    ConsoleSprite const &get_cells() const override {
        return cell;
    }

    void set_position(const vec2 &pos) {
        y = pos.first;
        x = pos.second;
    }

    // should move a piece to new position given, or throw exception if position is illegal
    virtual bool check_move(vec2 to) = 0;
    virtual bool check_capture(vec2 to) = 0;

    virtual ~Piece()=default;
};


#endif //CPP_TRAININGS_PIECE_H
