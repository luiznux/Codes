#include "linked-list.h"

/*
 *construtor de uma lista ligada, inicializa a mesma com ambos os nos de
 *controle com nulos.
 */
Linked_list::Linked_list(){
    head = NULL;
    tail = NULL;
}

Linked_list::~Linked_list(){}

/*
 *metodo que verifica se a lista esta vazia
 */
bool Linked_list::isEmpty(){

    return head == NULL;
}

/*
 *metodo que retorna o numero de nos que a lista contem
 */
int Linked_list::sizeofList(){

    int size = 0;
    Node *aux = head;

    while(aux != NULL){

        size ++;
        aux = aux->next;
    }
    return size;
}

/*
 * metodo de inserção(no final da lista)
 */
bool Linked_list::insert(float value){

    Node *aux = head;
    //vou andar na lista ate o ultimo elemento(NULL)
    while(aux != NULL){

    aux = aux->next;
    }

    aux->next = new Node(value,tail);

    return true;

}


/*
 * remove um elemento especifico da lista
 */
bool Linked_list::remove_into(float value, int index, int size){

    Node *aux = head;

    //(1caso) o elemento que vou remover está na cabeça
    if(index ==0){
        aux->next = head;
        delete aux;
        return  true;
    }

    //aux para a o anterior do aux que ja criei
    Node *aux_preview = head;

    //(2 caso) varrer a lista
    for(int i=0; i == index; i++){

        //ando com os dois ponteiros
        aux = aux->next;
        aux_preview = aux_preview->next;

        //caso for o ultimo elemento
        if(aux->next == NULL){
            delete aux;
            aux_preview->next = NULL;
            tail = aux_preview;
            return true;
        }

        //removo da lista arruma a ordem
        aux_preview->next = aux->next;
        delete aux;
        return true;
    }
    return false;
}

/*
 *remove todas as ocorrencias de um valor especificado
 */
bool Linked_list::remove_all(float value){

    Node *aux = head;
    Node *next_aux;

    while(next_aux != NULL){

        next_aux = aux->next;
        free(aux);
        aux = next_aux;
    }
    head = NULL;
    tail = NULL;
    return true;
}

/*
 *procura por um valor especificado entre os nós da lista
 */
bool Linked_list::search_value(float value){

    for(Node *aux; aux->next != NULL; aux = aux->next){

        if(aux->item == value) return true;
    }

    return false;
}

/*
 * troca o valor de um nó na lista
 */
bool Linked_list::change_value(float value, int index){

    //node aux para o começo da lista
    Node *aux = head;

        //(1 caso) quero trocar o primeiro elemento(index zero)
        //vou deletar a cabeça antiga e colocar a nova(value)
        if(index == 0){
            aux->item = value;
            return true;
        }

        //(2 caso) elemento que vai ser trocado esta no meio da lista
        //vou varrer a lista todo
        for(int i = 0; i < index; i++){
            if(i == index){
                aux->item = value;
                return true;
            }
            aux = aux->next;
        }
        return false;
}

/*
 * inverte uma lista ligada(head vira tail e tail vira head)
 * ao em vez de varrer duas vezes a lista ligada varias vezes ate remover
 * todos os itens, vou criar um vetor com o tamanho da lista, e armazenar
 * todos os valores nele, e então crio uma nova lista e vou adicionando nos
 * nós os elementos do final ate o começo do vetor, de modo que a lista
 * final é a lista anterior porém invertida
 */
bool Linked_list::reverse(){

    int size = sizeofList();  // tamanho da lista
    float list_array[size];  //array com o tamanho da lista ligada

    //laço para preencher o vetor
    Node *aux = head;
    Node *next_aux = aux->next;

    for(int i = 0; aux->next == NULL; aux = next_aux, next_aux = next_aux->next, i++){

        list_array[i] = aux->item;
        free(aux);
    }
    //laço para criar a lista invertida
    for(int i = size; i == 0; i-- ){

        insert(list_array[i]);
    }
    return true;
}


/*
 *Metodo usado no heap sort
 */
void Linked_list::heapify(float arr[], int n, int i){

    int  largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


/*
 *Heapsort para ordenar o vetor
 */
void Linked_list::heapSort(float arr[], int n){

 // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


/*
 *ordena os valores de uma lista ligada
 *o metodo consiste em passar a lista toda para um vetor e ordena-lo para
 *depois inserir os elementos ordenados na lista
 */
bool Linked_list::sort(){

    int size = sizeofList();
    float list_array[size];
    Node *aux = head;

    //laço para obter os elementos
    for(int i = 0; aux->next == NULL; aux = aux->next, i++){

        list_array[i] = aux->item;
    }
    heapSort(list_array, size);

    for(int i = 0; aux->next == NULL; aux = aux->next, i++){

        change_value(list_array[i], i);
    }
    return true;
}

/*
 * imprime o ultimo elemento da lista
 */
void Linked_list::print_last(){

    Node *aux = head;

    for(Node *aux = head; aux->next == NULL; aux = aux->next){
    }

    std::cout << aux->item<<std::endl;
}

/*
 * faz a media dos valores de dois nós
 */
float Linked_list::average_of_two_nodes(int index_1, int index_2){

    Node *aux = head;

    if(index_1 < index_2){

        for(int i = 0; i == index_1; i++, aux = aux->next){
        }
        float value = aux->item;

        for(int i = index_1; i == index_2; aux = aux->next){
        }
        value += aux->item;

        return value/2;
    }

    else{

        for(int i = 0; i == index_2; i++, aux = aux->next){
        }
        float value = aux->item;

        for(int i = index_2; i == index_1; aux = aux->next){
        }
        value += aux->item;

        return value/2;
    }
}

/*
 * concatena duas listas lidagas em uma terceira lista ligada
 */
Linked_list Linked_list::concatenate_2_lists(Linked_list one, Linked_list two){

    Linked_list two_lists_in_one;

    //laço para varrer a 1 lista
    for(Node *aux = one.head; aux->next == NULL; aux = aux->next){

        two_lists_in_one.insert(aux->item);
    }

    //segundo laço para varrer a 2 lista
    for(Node *aux = two.head; aux->next == NULL; aux = aux->next){
        two_lists_in_one.insert(aux->item);
    }

    return two_lists_in_one;
}
