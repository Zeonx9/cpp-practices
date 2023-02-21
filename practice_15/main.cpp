//
// Created by musht on 13.02.2023.
//

#define CHESS

#ifdef SHAPES
#include <vector>
#include "shapes/ShapeFactory.h"

int main() {
    std::vector<Shape*> shapes;
    int n;
    std::cout << "Enter number of shapes:\n";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        shapes.push_back(ShapeFactory::scan());
    }

    auto comp = [](const Shape * a, const Shape * b) {
        return a->get_perimeter() >= b->get_perimeter();
    };
    std::sort(shapes.begin(),shapes.end(),comp);

    for (auto shape : shapes) {
        std::cout << shape->get_id() << " " << shape->get_perimeter() << "\n";
    }
}
#endif

#ifdef CHESS

#include <memory>
#include "chess/game/ClassicGame.h"
#include "chess/render/console/ConsoleRenderer.h"

int main() {
    std::shared_ptr<Renderer> renderer = std::make_shared<ConsoleRenderer>(12, 12);
    std::unique_ptr<Game> game = std::make_unique<ClassicGame>(renderer);
    game->start();
}
#endif

