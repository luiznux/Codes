
typedef struct{ //tipo fração(a/b) contendo nominador(a) e denominador(b)
    int nom; //nominador
    int dem; //denominador
}fraction;


/*
  função para calcular a soma de frações, recebedo como parametros as duas frações
  e retornando a fração resultante
 */
fraction sum(fraction a, fraction b){

    fraction answ;
    answ.nom = (a.nom*b.dem + b.nom*a.dem);
    answ.dem = a.dem*b.dem;
    return answ;
}

/*
  função para calcular a subtração de frações, recebedo como parametros as duas frações
  e retornando a fração resultante
 */
fraction sub(fraction a, fraction b){

    fraction answ;
    answ.nom = (a.nom*b.dem - b.nom*a.dem);
    answ.dem = a.dem*b.dem;
    return answ;
}

/*
  função para calcular a multiplicação de frações, recebedo como parametros as duas frações
  e retornando a fração resultante
 */
fraction mult (fraction a, fraction b){

    fraction answ;
    answ.nom = a.nom*b.nom;
    answ.dem = a.dem*b.dem;
    return answ;
}

/*
  função para calcular a divisao de frações, recebedo como parametros as duas frações
  e retornando a fração resultante
 */

fraction div (fraction a, fraction b){

    fraction answ;
    answ.nom = a.nom*b.dem;
    answ.dem = a.dem*b.nom;
    return answ;
}

/*
  função para verificar se as duas frações sao iguais
*/
int  equal (fraction a, fraction b){

    if(a.nom*b.dem == a.dem*b.nom) return 1;
    return 0;
}

