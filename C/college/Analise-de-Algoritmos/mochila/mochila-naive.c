#include <stdio.h>
#include <stdlib.h>

/*
  O que é o problema da mochila?
  - Quantas coisas cabem na mochila, baseada em sua capacidade e nos pesos dos itens, visando maximizar o valor dos itens inseridos

  Como fazer isso?
  - Uma mochila, ela é feita de submochilas, por exemplo, sua mochila ela é feita de submochilas que podem ser chamadas de bolsos
  - A quantidade de itens que cabe na mochila é a quantidade de itens que cabe em todos os bolsos

  Como escolher qual a melhor combinação de itens para entrarem na mochila?
  - Você não sabe qual a melhor combinação, logo você precisa testar todas as combinações possíveis

  Observação: Se a mochila tem tamanho 0, logo não cabe nada (Caso base):

  Como testar tudo?
  - Primeiro caso: O item não cabe na mochila
  - Segundo caso: O item cabe na mochila
 */
//=========================================================================================

/* -a função mochila recebe o vetor dos pesos, vetor dos valores,
   -o "n" é o indice do objeto que esta sendo comparado, a quantidade de
   objetos que voce quer comparar
   -o "c" é a capacidade da mochila
 */
int mochila(int *peso, int *valor, int n, int c){

    //caso base em que nao cabe nada da mochila
    if(n ==-1)
        return 0;

    //objeto que estou comparando
    int a = mochila(peso, valor, n-1, c);
    //
    if(peso[n] > c)
        return a;

    //segundo objeto que combina com o "a"
    int b = mochila(peso, valor, n-1, (c-peso[n])) + valor[n];
    printf("%d %d %d %d %d",a, b, valor[n],peso,n);

    return max(a,b);
}


int main(){

int p[] = {2,3,4};

int v[] = {5,8,9};

}

