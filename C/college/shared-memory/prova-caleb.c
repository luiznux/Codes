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

void  ClientProcess(int []);

int   main(int  argc, char *argv[])
{
    int    ShmID;
    int    *ShmPTR;
    pid_t  pid;
    int    status;

    if (argc != 2){
        printf("Use: %s #1 \n", argv[0]);
        exit(1);
    }

    //criei um processo pai, gerou regiao de memoria

    //ALOQUEI UMA REGIAO DE MEMORIA COMPARTILHADA PARA O PROCESSO PAI
    ShmID = shmget(IPC_PRIVATE, 1*sizeof(int), IPC_CREAT | 0666);

    if (ShmID < 0){ //os if serve para verificar se deu certo a alocação
        printf("*** shmget error (server) ***\n");
        exit(1);
    }
    printf("Server has received a shared memory of one integer...\n");

    // salvo nessa variavl o ponteiro para a regiao de mememoria compartilhada
    ShmPTR = (int *) shmat(ShmID, NULL, 0);
    if ((int) ShmPTR == -1) { //verificação se deu certo
        printf("*** shmat error (server) ***\n");
        exit(1);
    }
    printf("Server has attached the shared memory...\n");

    //atribui um valor ao processo de acordo com o imput do binario
    ShmPTR[0] = atoi(argv[1]);
    printf("Server has filled %d in shared memory...\n",ShmPTR[0]);

    //QUANDO FAÇO O FORK, VOU PARA FUNÇÃO LA DE BAIXO E EXECUTO A OPERAÇÃO de soma
    printf("Server is about to fork a child process...\n");
    pid = fork();
    if (pid < 0) { //verifico se o fork funcionou
        printf("*** fork error (server) ***\n");
        exit(1);

    }else if (pid == 0) { //se funcionou vou chamar a função de filho e fazer as alterações
        ClientProcess(ShmPTR);
        exit(0);
    }

    //agora vou mostrar os valores do pai alterado
    wait(&status);
    printf("Valor do pai após o fork %d \n",ShmPTR[0]);
    printf("O valor do pai foi alterado %d \n",ShmPTR[0] = ShmPTR[0] +1);
    printf("Server has detected the completion of its child...\n");
    shmdt((void *) ShmPTR);
    printf("Server has detached its shared memory...\n");
    shmctl(ShmID, IPC_RMID, NULL);
    printf("Server has removed its shared memory...\n");
    printf("Server exits...\n");
    exit(0);
}

//FILHOOOOO ->
void  ClientProcess(int  SharedMem[])
{
        //MEXENDO NO FILHO, ALTERANDO O VALOR
         printf("   Client process started\n");
         printf("   Client found %d in shared memory\n",SharedMem[0]);
         printf("   Valor do filho %d \n",SharedMem[0]);
         SharedMem[0]++;
         printf("   Apos a soma %d\n",SharedMem[0]);
         printf("   Client is about to exit\n");
}
