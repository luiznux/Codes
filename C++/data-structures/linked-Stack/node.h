#ifndef NODE_H
#define NODE_H

class Node{


private:

    float value;
    Node *next;

public:

    Node(float item, Node *new_node);

    ~Node();
};
#endif
