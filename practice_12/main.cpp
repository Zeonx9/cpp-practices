//
// Created by musht on 13.01.2023.
//

#define A
#include "graph.h"


#ifdef A

int main() {
    auto graph = Graph();

    graph.add_node(1, "a", 3);
    graph.add_node(2, "b", 4);
    graph.add_node(3, "a", 5);
    graph.add_node(4, "c", 18);
    graph.add_node(5, "a", -2);

    graph.add_edge(1, 5);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(4, 2);

    std::string key;
    std::cout << "enter key to find:";
    std::cin >> key;

    auto print_info = [key](const Node &node) {
        if (node.key == key)
            std::cout << "found: Node{id=" <<  node.id
                      << ", key=\"" << node.key
                      << "\", value=" << node.value << "}\n";
    };

    graph.bfs(print_info, 1);
}
#endif
