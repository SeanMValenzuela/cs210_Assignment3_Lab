//
// Created by Sean Valenzuela on 9/17/26.
//

# pragma once

template <typename T>
class Node {
public:
    T *value;
    Node<T> *next;

    Node(T *value) {
        this->value = value;
        next = nullptr;
    }
    void print() {
        value->print();
    }
};
