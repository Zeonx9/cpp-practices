//
// Created by musht on 19.02.2023.
//

#ifndef CPP_TRAININGS_CONSOLERENDERER_H
#define CPP_TRAININGS_CONSOLERENDERER_H

#include <vector>
#include <iostream>
#include "../Renderer.h"

// implementation of Console Renderer that puts everything out in console
class ConsoleRenderer : public Renderer {
protected:
    int width, height;
    std::vector<std::vector<ConsoleCell>> canvas;

public:
    explicit ConsoleRenderer(int h, int w) {
        width = w;
        height = h;
        canvas = ConsoleDrawable::ConsoleSprite(h, std::vector<ConsoleCell>(w, ConsoleCell('-')));
    }

    void show() override {
        for (auto &cell_row : canvas) {
            for (int i = 0; i < ConsoleCell::shape().first; ++i) {
                for (auto &cell : cell_row) {
                    std::cout << cell.get_row(i);
                }
                std::cout << '\n';
            }
        }
    }

    void draw(const ConsoleDrawable &drawable, vec2 offset) override {
        auto [a, b] = offset;
        auto [h, w] = drawable.get_size();
        auto [y, x] = drawable.get_coordinates();
        auto cells = drawable.get_cells();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                canvas[y + i + a][x + j + b] = cells[i][j];
            }
        }
    }

    void draw(const ConsoleDrawable &drawable) override {
        draw(drawable, vec2{0, 0});
    }

    void clear() override {
        canvas = ConsoleDrawable::ConsoleSprite(height, std::vector<ConsoleCell>(width, ConsoleCell('-')));
    }
};


#endif //CPP_TRAININGS_CONSOLERENDERER_H
