#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "node.h"


class Double_linked_list{

private:

    Node *head, *tail;

public:

    Double_linked_list();
    ~Double_linked_list();
    bool IsEmpty();
    bool Insert(float value);
    bool Insert_start(float value);
    bool Insert_end(float value);
    bool Remove_first();
    bool Remove_last();
    bool Remove_value(float value);
    bool Is_in_List(float value);
    void print_List();
    void inverse_print_List();
    float middle_value();
    void insertionSort(float *arr, int n);
    void sort_list();
};
#endif
