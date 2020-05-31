#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <iostream>

class Stack{

private:

    Node *top_stack;

public:

    Stack();
    ~Stack();
    bool empty();
    bool push(float item);
    bool pop();
    bool top(float &item);
    void print();
};
#endif
