#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <unistd.h>

/*
  O exercicio consiste em provar e o shared memory funciona de fato, a questao é, como?
  Vamos criar um processo no sistema operacional, chamar a função shmget para alocar uma regiao de memoria
  compartilhada, salvar o retorno da função shmat(que retorna o ponteiro da regiao de memoria alocada) em uma
  variavel do tipo ponteiro
  Apos isso, vamos fazer um fork do processo pai, onde vamos alterar o valor da variavel do filho,  seguindo a
  logica tudo que eu alterar no filho na regiao de memoria compartilhada, tambem vai se alterar no pai.
  Pelo fato de quando forkeio copio tudo que esta no pai para o filho(INCLUSIVE A REGIAO DE MEMROIA COMPARTILHADA), se eu alterar a regiao de memoria compartilhada do filho, a mudança vai continuar para o pai tambem.
  Assim exibindo os valores do pai, provando que a regiao de memoria compartilhada funciona !
 */

/*
  Função que altera os dados na shared memory do processo pai
 */
void  Processo_Filho(int  memoria[])
{
   //MEXENDO NO FILHO, ALTERANDO O VALOR
    printf("\n        Valor do filho %d\n",memoria[0]);
    memoria[0]++;
    printf("        Apos a soma %d\n",memoria[0]);
    printf("        Saindo do fork....\n");
}


int   main()
{
    printf("NOMES: \n Luiz Fernando 31861806 \n Thiago Valença 31885731 \n\n");
    int    ShmID;
    int    *ShmPTR;
    pid_t  pid;
    int    status;

    //aloco memoria compartilhada de tamnho 1 do tipo inteiro
    ShmID = shmget(IPC_PRIVATE, 1*sizeof(int), IPC_CREAT | 0666);

    // salvo nessa variavel o ponteiro para a regiao de mememoria compartilhada
    ShmPTR = (int *) shmat(ShmID, NULL, 0);

    ShmPTR[0] = 1;
    printf("Valor do pai antes do fork.... %d \n",ShmPTR[0]);

    printf("Fiz o fork ........\n");
    pid = fork();
    if (pid < 0) { //verifico se o fork funcionou
        printf("*** ERRO FORK ***\n");
        exit(1);

    }else if (pid == 0) { //se funcionou vou chamar a função de filho e fazer as alterações
        Processo_Filho(ShmPTR);
        exit(0);
    }

    /*
    o wait é necessario para que  os prints sejam exibidos corretamente,
    pois sem eles, as alterações do fork so serão mostradas apos toda
    execução do main, em outras palavras, estou esperando tudo que esta a
    cima de mim(wait) acabar para dar continuidade
    */
    wait(&status);
    printf("\n-Apos o fork, o valor do pai é... %d\n",ShmPTR[0]);
    printf("-Somando +1 no pai..... %d + 1\n",ShmPTR[0]);
    ShmPTR[0]++;
    printf("-Valor final do pai --> %d\n",ShmPTR[0]);
    printf("Desalocando a memoria compartilhada... \n");
    shmdt((void *) ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);
    exit(0);
}

