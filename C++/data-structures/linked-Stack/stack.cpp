#include "stack.h"


//construtor de uma pilha
Stack::Stack(){

    //contruo uma pilha vazia com o top dela apontando para NULL
    top_stack  = NULL;
}


//destruidor de uma pilha
Stack::~Stack(){

}


//verifica se a pilha esta vazia
bool Stack::empty(){

    //retorno o booleano do top, se ele conter elementos ==true se nao false
    return top_stack == NULL;

}


//insere um elemento no topo da pilha
bool Stack::push(float item){

    //crio um novo topo com parametro item
    //aloco memoria com o item e seto o apontador dele para o
    //antigo topo da pilha
    Node *new_top = new Node(item, top_stack);

   //verfico se o novo topo foi alocado com sucesso
   //ele deve retornar um ponteiro para node caso de certo
    if(new_top == NULL)
        return false;

    //o topo da pilha agora recebe o novo topo
    top_stack = new_top;
    return true;
}


//retira o elemento do topo da fila
bool Stack::pop(){

    if(top_stack == NULL)
        return false;

    //armazeno o endereço do antigo topo
    Node *old_top = top_stack;
    top_stack = old_top - top_stack ;
}


bool Stack::top(float &item){

}


void Stack::print(){

}


