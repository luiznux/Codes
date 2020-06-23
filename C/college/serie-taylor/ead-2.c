#include <stdio.h>
#include <math.h>
const double EULER = 2.71828182845904523536;

// contador para saber quantas vezes entra na função
int contador;


// função do fatorial
int fatorial(int n){
    contador++;
    if(n < 2){
       return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}



// o x é o f(x) e o n é ate onde vc quer que calcule a somatoria
double euler_de_x(int  x, int n){


    // variavel que armazena o resultado das somas
    float somatoria;

    for(double i = 0; i <= n; i++){
        contador++;
        somatoria+= pow(x,i) / fatorial(i);
    }


    return somatoria;
}



int main(){

    int xis = 3;

    int ene = 10;

    long double x_do_euler = euler_de_x(xis, ene);

    printf("\n O resultado do x do euler é: %Lf", x_do_euler);

    printf("\n O resultado do Euler é: %f", pow(EULER,xis));

    printf("\n O contador de chamadas de função resulta em: %d",contador);

    return 0;
 }

