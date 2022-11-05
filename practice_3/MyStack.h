//
// Created by musht on 15.10.2022.
//

#ifndef CPP_TRAININGS_MYSTACK_H
#define CPP_TRAININGS_MYSTACK_H

#include <iostream>

class IntNode {
public:
    int val;
    IntNode *next;
    IntNode(int v, IntNode *nxt) : val(v), next(nxt) {}
};

class MyStack {
private:
    IntNode *top;
    int size;
public:
    MyStack() {
        top = nullptr;
        size = 0;
    }
    ~MyStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    void put(int val) {
        top = new IntNode(val, top);
        ++size;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Underflow of Stack\n";
            exit(-678);
        }
        auto node = top;
        top = top->next;
        --size;
        auto val = node->val;
        delete node;
        return val;
    }

    int peek() const {
        return top->val;
    }
};


#endif //CPP_TRAININGS_MYSTACK_H
