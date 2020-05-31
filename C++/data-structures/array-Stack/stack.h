#ifndef STACK_H
#define STACK_H
#include <iostream>

//tamanho fixo da pilha
#define size 40

class Stack{

     private:

        //atributo que gerencia os indices
        int cont;

        // vetor da pilha
        int array_stack[size];


     public:

        Stack();
        ~Stack();
        bool isEmpty();
        bool full();
        bool pop();
        bool push(int value);
        bool top(int &value);
        void check_top();
        bool equal(Stack &S);
        void reverse_stack();
        void reverse_another_stack(Stack &S);
        void copie_stack(Stack &);
        void print_stack();
};
#endif
