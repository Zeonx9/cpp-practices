//
// Created by musht on 18.02.2023.
//

#ifndef CPP_TRAININGS_RENDERER_H
#define CPP_TRAININGS_RENDERER_H


#include <memory>
#include <utility>
#include "console/ConsoleDrawable.h"
#include "../util/util.h"

// encapsulates the logic of rendering the objects
class Renderer {
public:
    // methods that puts out a given drawable into inner representation of that object
    virtual void draw(const ConsoleDrawable &drawable) = 0;
    virtual void draw(const ConsoleDrawable &drawable, vec2 offset) = 0;
    // shows current drawn objects
    virtual void show() = 0;
    // clears all previously drawn objects
    virtual void clear() = 0;

    virtual ~Renderer() {
        std::cout << "Renderer destroyed\n";
    }
};


#endif //CPP_TRAININGS_RENDERER_H
