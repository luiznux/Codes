#include "stack.h"

Stack::Stack(){
    cont = 0;
}

Stack::~Stack(){
}

// Verifica se a pilha é isEmpty
bool Stack::isEmpty(){

  /*Se a Stack esta isEmpty, retorna true, se nao, retorna false*/
  if(cont > 0) return false;
  return true;
}

// Verifica se a pilha esta cheia
bool Stack::full(){

    if(size == cont) return true;
    return false;
}

//remove o elemento do topo
bool Stack::pop(){
 /*
  *Se a Stack nao esta isEmpty, topo da pilha eh removido.
  *Se a pilha esta isEmpty um codigo de erro de underflow eh retornado
  */
  if(isEmpty() == true)
     return false;

  --cont;
 return true;

}

// insere no topo da pilha
bool Stack::push(int value){

    if(full() == true)
        return false;

    //adiciono o valor no topo da pilha
    array_stack[cont] = value;
    cont ++;
    return true;
}

//retorna o valor do primeiro elemento para o endereço do parametro dado
bool Stack::top(int &value){

    if(isEmpty() == true)
        return false;

    value = array_stack[cont -1];
    return true;
}

//printa o elemento do topo da pilha
void Stack::check_top(){

    std::cout <<"O elemento do topo é: "<< array_stack[cont] << std::endl;
}

//verifica se uma pilha é igual a outra
bool Stack::equal(Stack &S){

    Stack auxiliar;

    int v1, v2,vaux;

    bool igual = true;

    if(cont == S.cont){
        //laçopara a verificação
        while(isEmpty() != true && S.isEmpty() != true && igual == 1){

               top(v1);
               S.top(v2);

               if(v1 != v2) igual = 0;

               else{

                  pop();
                  S.pop();
                  auxiliar.push(v1);
              }
       }

        while(auxiliar.isEmpty() != true){

              auxiliar.top(vaux);
              push(vaux);
              S.push(vaux);
              auxiliar.pop();
       }
       return igual;
   }
    else return false;
}

//inverte a pilha
void Stack::reverse_stack(){

    int value;
    Stack aux;
    Stack aux2;

    //passo da original para aux
    while(!isEmpty()){
        top(value);
        pop();
        aux.push(value);
    }
    /*
    while(!aux.isEmpty()){
        aux.top(value);
        aux.pop();
        aux2.push(value);
    }

    while(!aux2.isEmpty()){
        aux2.top(value);
        aux2.pop();
        push(value);
    }
    */
    Stack() = aux;

}

// inverte  outra pilha
void Stack::reverse_another_stack(Stack &S){

    int value;
    Stack aux;

    while(!isEmpty()){
        top(value);
        pop();
        S.push(value);
        aux.push(value);
    }

    while(!aux.isEmpty()){
        aux.top(value);
        aux.pop();
        push(value);
    }
}


/*Copio uma pilha para outra pilha
 *uso uma pliha aux para passar da principal para aux, e deps da aux para a
 *principal e a copia(A e A')'
 */
void Stack::copie_stack(Stack &S){

    int value;
    Stack aux;

    //laço para a mover a pilha principal para a aux
    while(!isEmpty()){

        top(value);
        pop();
        aux.push(value);
    }

    //laço para tirar da aux e passar para A e A'
    while(!aux.isEmpty()){

        aux.top(value);
        aux.pop();
        S.push(value);
    }
}

//imprime uma pilha
void Stack::print_stack(){

    int value;
    Stack aux;

    /* laço para desempilhar a pilha original e imprimir, ao mesmo tempo
     * que eu salvo os itens desempilhados na pilha aux
     */
    while(isEmpty() != true){

        std::cout <<"\n       | "<< top(value) << " |";
        pop();
        aux.push(value);
    }
    std::cout << "\n \n";

    /*laço para devolver os intens da pilha aux para a original, lembrando
      que a pliha aux estara ao contrario da pilha original,
      exemplo orig 1234, aux 4321 */
    while(!aux.isEmpty()){

        aux.top(value);
        aux.pop();
        push(value);
    }
}
