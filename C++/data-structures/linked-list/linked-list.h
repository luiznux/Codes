#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

class Linked_list{

private:

    Node *head, *tail;

public:

    Linked_list();
    ~Linked_list();
    bool isEmpty();
    int sizeofList();
    bool insert(float value);
    bool remove_into(float value, int index, int size);
    bool remove_all(float value);
    bool search_value(float value);
    bool change_value(float value,int index);
    bool reverse();
    void heapify(float arr[], int n, int i);
    void heapSort(float arr[], int n);
    bool sort();
    void print_last();
    float average_of_two_nodes(int index_1, int index_2);
    Linked_list concatenate_2_lists(Linked_list one , Linked_list two);

};
#endif
