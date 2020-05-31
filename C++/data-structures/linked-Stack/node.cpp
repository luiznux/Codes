#include "node.h"

Node::Node(float item, Node *new_node){

    value = item;
    next = new_node;
}

Node::~Node(){
}
