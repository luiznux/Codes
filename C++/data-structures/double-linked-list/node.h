#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node{


    float item;

    Node *next, *preview;

    Node(){
        next = preview = NULL;
    }

    Node(int value, Node *p, Node *n){

        item = value; next = n, preview = p;
    }
};
#endif
