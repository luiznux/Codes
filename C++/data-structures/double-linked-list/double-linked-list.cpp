#include "double-linked-list.h"

Double_linked_list::Double_linked_list(){

    head = tail = NULL;
}

Double_linked_list::~Double_linked_list(){}


bool Double_linked_list::IsEmpty(){

    return head == NULL;
}

//insere no final(depois do tail)
bool Double_linked_list::Insert(float value){

    //verifica se nao está vazia e insiro o primeiro elemente
    if(IsEmpty()){
        Node *new_node = new Node(value,NULL,NULL);
        head = tail = new_node;
        return true;
    }
    Node *aux;
    for(aux = head; aux->next != NULL; aux = aux->next){
    }
    aux->next = new Node(value,aux,NULL);
    tail = aux->next;
    return true;
}

bool  Double_linked_list::Insert_start(float value){

    //verifica se nao está vazia e insiro o primeiro elemente
    if(IsEmpty()){
        Node *new_node = new Node(value,NULL,NULL);
        head = tail = new_node;
        return true;
    }

    head->preview = new Node(value,NULL,head);
    head = head ->preview;
    return true;
}

bool Double_linked_list::Insert_end(float value){

    //verifica se nao está vazia e insiro o primeiro elemente
    if(IsEmpty()){
        Node *new_node = new Node(value,NULL,NULL);
        head = tail = new_node;
        return true;
    }

    tail->preview = new Node(value,tail,NULL);
    tail = tail->next;
    return true;
}

bool Double_linked_list::Remove_first(){

    Node *aux = head->next;
    delete head;
    head = aux;
    aux->preview = NULL;
    return true;
}

bool Double_linked_list::Remove_last(){

    Node *aux = tail->preview;
    delete tail;
    tail = aux;
    tail->next = NULL;
    return  true;

}

bool Double_linked_list::Remove_value(float value){

    for(Node *aux = head; aux->next != NULL; aux = aux->next){
        if(aux->item == value){
            aux->preview->next = aux->next;
            delete aux;
        }
    }
    return true;
}

bool Double_linked_list::Is_in_List(float value){

    for(Node *aux = head; aux->next != NULL; aux = aux->next){
        if(aux->item ==value)break ;
    }
    return  true;
}

void Double_linked_list::print_List(){

    for(Node *aux = head; aux != NULL; aux = aux->next){
        std::cout << aux->item << " "<< std::endl;
    }
}

void Double_linked_list::inverse_print_List(){

    for(Node *aux = tail; aux->preview != NULL; aux = aux->preview){
        std::cout << aux->item << " "<< std::endl;
    }
}

/*
 * calcula o valor do elemento medio de uma lista usando dois aux,
 * que começa na cabeça e outro no tail, caso seja par a lista ele retorna
 * a media dos valores do meio
 */
float Double_linked_list::middle_value(){

    Node *aux_start = head;
    Node *aux_end = tail;

    while(true){

        //é impar  a lista
        if(aux_start == aux_end){
            return aux_start->item;

            //é par
        }else if(aux_start->next == aux_end){
            return (aux_start->item + aux_end->item)/2;
        }
        aux_start = aux_start->next;
        aux_end = aux_end->preview;
    }
}
void Double_linked_list::insertionSort(float *arr, int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
 *o metodo consiste em passar uma copia dos valores da lista para um vetor
 *de mesmo tamanho(trei que percorrer a lista para saber o tamanho),e entao
 *ordeno o vetor e altero o valor de cada no da lista com os valores do ve-
 *vetor ja ordenado
 */
void Double_linked_list::sort_list(){

    int size = 0;

    //calculo do tamanho
    for(Node *aux = head;aux != NULL; aux = aux->next){
        size++;
    }

    //preenchendo o vetor
    float vector[size];
    int i = 0;
    for(Node *aux = head; aux != NULL && i < size; aux = aux->next, i++){
        vector[i] = aux->item;
    }

    //ordeno e altero a lista original
    insertionSort(vector, size);
    i = 0;
    for(Node *aux = head; aux != NULL && i < size; aux = aux->next, i++){

        aux->item = vector[i];
    }
}
