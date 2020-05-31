#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node
{

// data members
	float item;
    Node *next;

	// constructors
	Node(float value, Node *ptr)
    {
        ptr = NULL;

        item = value; next =ptr;
    }
};
#endif
