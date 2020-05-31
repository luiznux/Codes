#include "double-linked-list.h"

int main(){

    Double_linked_list teste;

    for(int i = 0; i < 5; i++){
        teste.Insert(i);
    }

    teste.print_List();
    std::cout<<" \n "<<std::endl;

    teste.Remove_first();

    return 0;
}
