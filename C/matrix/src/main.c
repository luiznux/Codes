#include "matrix.h"

//defino uma constante de tamanho para as matrizes
const int MAX = 100;

int main(){

    //aloco ambas as matrizes
    int** A = calloc_matrix(MAX,MAX);
    int** B = calloc_matrix(MAX,MAX);

    //preencho as mesmas
    fills_rand_matrix(A, MAX, MAX, 50);
    //fills_rand_matrix(B, MAX, MAX, 100);

    //realizo o teste da maneira ingenua
    // mult_matrix_dump(A, MAX, B, MAX);

return 0;
}
