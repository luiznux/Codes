#ifndef FILA_H
#define FILA_H

#define tam 10

class Fila{

  private:

     int vetorfila[tam];

     int inicio,  contador;

  public:

     Fila();
     bool vazia();
     bool cheia();
     bool insere(int item);
     bool remove();
     bool consulta(int &item);
     void copia(Fila &F);
     bool iguais(Fila F);
     int tamanho();
     void printa();
};
#endif
