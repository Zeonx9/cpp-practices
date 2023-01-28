//
// Created by musht on 26.01.2023.
//

#ifndef CPP_TRAININGS_GRAPH_H
#define CPP_TRAININGS_GRAPH_H

#include <vector>
#include <map>
#include <functional>
#include <stack>
#include <iostream>

class Node {
public:
    int id;
    std::string key;
    int value;
    Node(int i, std::string k, int v) : id(i), key(std::move(k)), value(v) {}
    Node() : Node(0, "", 0) {}
    explicit Node(int i) : Node(i, "", 0) {}
};

class Graph {
private:
    int last_id = 0;
    std::map<int, Node> nodes;
    std::map<int, std::vector<int>> adj_lists;

public:
    void add_node(int id, const std::string &key, int value) {
        nodes[id] = Node(id, key, value);
    }

    void add_edge(int id1, int id2) {
        if (!nodes.contains(id1))
            nodes[id1] = Node(id1);
        if (!nodes.contains(id2))
            nodes[id2] = Node(id2);

        adj_lists[id1].push_back(id2);
        adj_lists[id2].push_back(id1);
    }

    Node get_by_id(int id) {
        if (!nodes.contains(id)) {
            std::cerr << "no such node in graph";
            exit(100);
        }
        return nodes[id];
    }

    void dfs(const std::function<void(const Node &)>& func, int start_id) {
        std::map<int, bool> visited;
        std::stack<int> stack;
        stack.push(start_id);

        while (!stack.empty()) {
            int cur_id = stack.top();
            stack.pop();

            func(get_by_id(cur_id));
            visited[cur_id] = true;

            for (int next_id : adj_lists[cur_id]) {
                if (visited.contains(next_id) and visited[next_id])
                    continue;

                stack.push(next_id);
            }
        }
    }

    void bfs(const std::function<void(const Node &)> &func, int start_id) {
        std::map<int, bool> visited;
        std::deque<int> deque;
        deque.push_back(start_id);

        while (!deque.empty()) {
            int cur_id = deque.front();
            deque.pop_front();

            func(get_by_id(cur_id));
            visited[cur_id] = true;

            for (int next_id : adj_lists[cur_id]) {
                if (visited.contains(next_id) and visited[next_id])
                    continue;

                deque.push_back(next_id);
            }
        }
    }
};


#endif //CPP_TRAININGS_GRAPH_H
