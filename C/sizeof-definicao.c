#include <stdio.h>


#define ARRAY_SIZE(x) sizeof(x) / sizeof(x[0]) /*calcula o tamanho do array em bytes
                                                 divide o tamaho em bytes pelo tamanho do primeiro elemento
                                                 asssim consigo saber o numero de elementos dele
                                               */

/* tipo inteiro sem sinal */
    size_t sizeof_array(char *array){ /* ponteiro para char tem 8 bytes */

    return sizeof(array);
}


int main(){

    char single_character = 'a'; /* m byte de tamanho */
    printf("Single character size: %zu\n", sizeof(single_character));

        char array_of_characters[] = {'a', 'b', 'c'}; /* array de char */
    printf("Array of characters size: %zu\n", sizeof(array_of_characters));
    printf("Array of characters size: %zu\n", ARRAY_SIZE(array_of_characters));



    char *string = "Hello, World";
    printf("String size: %zu\n", sizeof(string));

    return 0;
}
