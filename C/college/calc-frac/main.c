#include <stdio.h>
#include "frac.h"

int main(){

    fraction uno, dos; //crio 2 frações

    printf("Digite seu numerador para a primeira fração: \n ->");
    scanf("%d", &uno.nom);

    printf("Digite seu denomidanor para a primeira fração: \n ->");
    scanf("%d", &uno.dem);

    printf("Digite seu numerador para a segunda fração: \n ->");
    scanf("%d", &dos.nom);

    printf("Digite seu denomidanor para a segunda fração: \n ->");
    scanf("%d", &dos.dem);

    printf("%d/%d",sum(uno,dos).nom, sum(uno,dos).dem);

    return 0;
}
