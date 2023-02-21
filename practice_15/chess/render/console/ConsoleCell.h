//
// Created by musht on 20.02.2023.
//

#ifndef CPP_TRAININGS_CONSOLECELL_H
#define CPP_TRAININGS_CONSOLECELL_H

#include <vector>
#include <string>
#include "../../util/util.h"

// drawable should be composed of such cells
class ConsoleCell {
private:
    std::vector<std::string> repr;

public:

    // number of rows and columns which each cell occupies
    static vec2 shape() {
        return vec2 {2, 5};
    }

    explicit ConsoleCell(char fill=' ') {
        auto [a, b] = shape();
        for (int i = 0; i < a; ++i) {
            repr.emplace_back(b, fill);
        }
    }

    std::string get_row(int row) const {
        return repr[row];
    }

    void set_text_center(const std::string &str, int row) {
        int i = (shape().second - (int) str.size()) / 2;
        for (auto ch : str) {
            repr[row][i++] = ch;
        }
    }

    void fill_row(char fill, int row) {
        for (char &ch : repr[row]) {
            ch = fill;
        }
    }

    void set_right_fill(char fill) {
        for (int i = 0; i < shape().first; ++i) {
            repr[i][shape().second - 1] = fill;
        }
    }

    void set_fill(char fill) {
        for (int i = 0; i < shape().first; ++i) {
            fill_row(fill, i);
        }
    }
};


#endif //CPP_TRAININGS_CONSOLECELL_H
