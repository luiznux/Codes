#include "fila.h"
#include <iostream>

using namespace std;

int main()
{
      int opcao;
      int x;
      Fila F,F2,Fcopy;
      do{
        cout<<"\n\t\t\tFILA\n";
        cout<<"Digite 1 para inserir\n";
        cout<<"Digite 2 para remover\n";
        cout<<"Digite 3 para consultar\n";
        cout<<"Digite 4 para copiar\n";
        cout<<"Digite 0 para sair\n";
        cin>>opcao;
        switch(opcao){
           case 1:cout<<"Digite o elemento:";cin>>x;
                  if(F.insere(x)==1) cout<<"Insercao realizada com sucesso\n";
                  else cout<<"OVERFLOW\n";
                  break;
           case 2: if(F.remove()==0) cout<<"\nUnderflow\n";
                   else  cout<<"Remocao realizada com sucesso";
                  break;
           case 3:
               F.printa();
                  break;
           case 0: cout<<"saindo...\n";
                  break;
           default: cout<<"opcao invalida\n";
        }
        system("PAUSE");
        system("CLS");
      }while(opcao!=0);
       return 0;
}
