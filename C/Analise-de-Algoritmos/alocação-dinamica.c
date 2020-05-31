#include <stdio.h>
#include <stdlib.h>

#define M 15
#define N 12


int **malloc2d (int r, int c){
  int i;
  int **t = malloc(r * sizeof(int *));
  for (i = 0; i < r; i++)
    t[i] = malloc (c * sizeof(int));
  return t;
}

void imprime2d (int **v, int r, int c){
  int i, j;
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++)
      printf("%d ", v[i][j]);
    printf("\n");
  }
}
void preenche2d (int **v, int r, int c){
  int i, j;
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++)
      v[i][j] = 0;
  }
}

int main(){
  int **w = malloc2d (M, N);
  preenche2d (w, M, N);
  imprime2d (w, M, N);
  return 0;
}
