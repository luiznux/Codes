#ifndef MATRIX_C
#define MATRIX_C


int **calloc_matrix(int line, int colum);

void fills_rand_matrix(int** matrix, int l, int c,int rand);

int print_matrix(int **matrix,int line, int colum);

int **mult_matrix_dump(int** A, int l_A, int** B,int c_B);

int **mult_matrix_intelligent(int** A, int c_A, int** B,int l_B);

#endif
