#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*
  Função para alocar dinamicamente uma matriz de tamanho dados como parametros linhas(line) e colunas(colum)
  A função retorna um ponteiro para uma matriz
 */
int **calloc_matrix(int line, int colum){

    //ponteiro para a matriz
    int** matrix;

    //aloco as linhas
    matrix = (int **) calloc (line,sizeof(int *));

    //aloco as colunas
    for(int l = 0; l < line; l++){
        matrix[l] = (int*) calloc(colum,sizeof(int));
    }
    return matrix;
}

/*
  Função para preencher uma matriz com numeros aleatoridos.
  Recebendo a matriz(matrix) e seus dados(l e c) e juntamente a semente de numeros aleatorios
  atrelados ao parametro "rand".
 */
void fills_rand_matrix(int **matrix, int l, int c,int rand){

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            matrix[i][j] = i*rand+j;
        }
    }
}

/*
  Função para imprimir uma matriz, recebe o ponteiro para a matriz(matrix), sua linha e coluna.
  Caso a matriz dada seja maior que 8(linhas ou colunas), nao sera possivel imprimir
 */
int print_matrix(int **matrix,int line, int colum){

    //caso a matriz for muito grande, nao dou print
    if(line >=  8 || colum >= 8){
        printf("Cannot print!!!");
        return -1;

    }for(int l = 0; l < line ; l++){
        printf("\n [ ");
        for(int c = 0; c < colum; c++){
            printf("%d ",matrix[l][c]);

        }printf("]");
    }
    printf("\n\n");
    return 0;
}

/*
  Função para multiplicar duas matrizes A e B.
  Recebendo as duas matrizes acompanhadas com  as coluas de uma(c_A) e as linhas de outra (c_B).
  Lembrando que este metodo desperdiça recursos computacionais do sistema por ser realizado de
  maneira ingenua(I J K).
  A função retorna uma matriz "C" resultado da operação
 */
int **mult_matrix_dump(int** A, int l_A, int** B,int c_B){

    //caso a multiplicação nao senja possivel
    if(l_A != c_B) exit(0);

    //aloco uma matriz com o tamanho das linhas de A e colunas de B
    int **C = calloc_matrix(l_A, c_B);

    //i - j - k
    for(int i = 0; i < l_A; i++){
        for(int j = 0; j < c_B; j++){
            for(int k = 0; k<l_A; k++){
            C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

/*
  Função similar á apresentada a cima, diferindo nos recursos computacionais, que no caso
  serão melhor utilizados apenas mudando uma linha do codigo ja mostrado
  (I K J)
 */
int **mult_matrix_intelligent(int** A, int l_A, int** B,int c_B){

    //caso a multiplicação nao senja possivel
    if(l_A != c_B) exit(0);

    //aloco uma matriz com o tamanho das linhas de A e colunas de B
    int **C = calloc_matrix(l_A, c_B);

    //i - k - j
    for(int i = 0; i < l_A; i++){
        for(int k = 0; k<c_B; k++){
            for(int j = 0; j < c_B; j++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
  return C;
}
