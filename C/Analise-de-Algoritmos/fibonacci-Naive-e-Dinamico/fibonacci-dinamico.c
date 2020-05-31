# include <stdio.h>

// contadores para as duas funçoes, a ruim e a boa(dinamica)
long long int  contador_ruim = 0;

long long int contador_bom = 0;



//função fibonacci
long long int fibo(int n){

    contador_ruim++;

    if(n == 0) return 0;

    else if (n == 1) return 1;

    else return fibo(n-1) + fibo(n-2);

}



//fib dinamico que usa um vetor para armazenar resultados previos , afim de ganhar mais tempo
long long int fib_dinamico( int n, long long int *vetor){

    contador_bom++;

    if(n == 0){
        vetor[0] = 0;
        return 0;
    }

    else if( n == 1 || n == 2){
        vetor[n] = 1;
        return 1;
    }

    else if (vetor[n-1] == -1){
        vetor[n]  = fib_dinamico(n-1, vetor) + fib_dinamico(n-2, vetor);

    }

    return vetor[n];

}


// preenche um vetor de -1 de acordo com usa entrada
void preenche_saporra(long long int *vetor, int tamanho){

    for(int i =0; i < tamanho; i++){
        vetor[i] = -1;
    }

}



int main(){

    int coisa;

    printf("Digita ai Bazilao um numero para calcular o fibonacci, gloria a Tayrone! S2 \n");

    scanf("%d", &coisa);

    long long int  vetor_coisa[coisa];

    preenche_saporra(vetor_coisa, coisa);
    printf("\n Fibo resulta em: %lld \n", fibo(coisa));
    printf("\n Contador ruim: %lld \n", contador_ruim);
    printf("\n Fibo rapidao : %lld \n",fib_dinamico(coisa, vetor_coisa));
    printf("\n Contador bom: %lld \n", contador_bom);
    fib_dinamico(coisa, vetor_coisa);

    return 0;
}

