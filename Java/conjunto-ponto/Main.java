import java.util.Scanner;

/*
Entrega da prova 1 - Paradigmas de Linguagens de Programação – 05N

Nós,

Bruno Severo Camilo - 41781619
Luiz Fernando - 31861806

declaramos que

todas as respostas são fruto de nosso próprio trabalho, não copiamos respostas de colegas externos à equipe, não disponibilizamos nossas respostas para colegas externos ao grupo e não realizamos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/

/* Classe ListaPonto */



  /* public static void main(String[] args) {
    Ponto p1 = new Ponto(1, 1);
    Ponto p2 = new Ponto(3, 1);
    //Ponto p3 = new Ponto(4, 5);
    ListaPonto lista = new ListaPonto(4);
    //inserindo final
    System.out.println(lista.adicionaFinal(p1));
    System.out.println(lista.adicionaFinal(p2));
    //lista.adicionaColecao(p3, 0);
    //lista.imprimeLista();
    //System.out.println(lista.primeiraocorrencia(p1));
    //lista.removePonto(2);
    System.out.println(lista.distanciaPonto());
    lista.imprimeLista();
    */

public class Main {

  public static void main(String[] args) {
    ListaPonto lista = new ListaPonto(0);
      while(true){

          System.out.println(" \n Escolha sua opcao: \n");
          System.out.println("(1) Escolher tamanho do vetor");
          System.out.println("(2) Adicionar um elemento no final do vetor");
          System.out.println("(3) Remover um elemento do vetor");
          System.out.println("(4) Adicionar um elemento em uma posicao");
          System.out.println("(5) Buscar um elemento no vetor");
          System.out.println("(6) Calcular a distancia dos pontos");
          System.out.println("(7) Calcular a circunferencia do ponto");
          System.out.println("(8) Sair do  programa \n -> ");
          Scanner input = new Scanner(System.in);
          int sc = input.nextInt();

          if (sc == 1){
              System.out.println("Digite um tamanho para lista de pontos: ");
              input = new Scanner(System.in);
              int tam = input.nextInt();
              lista = new ListaPonto(tam);

          }else if (sc == 2){
              System.out.println("Digite o x");
              input = new Scanner(System.in);
              int pontox = input.nextInt();
              System.out.println("Digite o y");
              input = new Scanner(System.in);
              int pontoy = input.nextInt();
              Ponto p = new Ponto(pontox, pontoy);
              lista.adicionaFinal(p);
          
          }
          else if (sc == 3){
              System.out.println("Digite um indice para remover do vetor: ");
              input = new Scanner(System.in);
              int ind = input.nextInt();
              lista.removePonto(ind);

          }else if (sc == 4){
              System.out.println("Digite um ponto para add na colecao: ");
              input = new Scanner(System.in);
              int ponto = input.nextInt();

              System.out.println("Digite o x");
              input = new Scanner(System.in);
              int pontox = input.nextInt();
              System.out.println("Digite o y");
              input = new Scanner(System.in);
              int pontoy = input.nextInt();
              System.out.println("Digite o índice: ");
              input = new Scanner(System.in);
              int ind = input.nextInt();
              Ponto p = new Ponto(pontox, pontoy);
              lista.adicionaColecao(p, ind);

          }else if (sc == 5){
              System.out.println("Digite o x");
              input = new Scanner(System.in);
              int pontox = input.nextInt();
              System.out.println("Digite o y");
              input = new Scanner(System.in);
              int pontoy = input.nextInt();
              Ponto p = new Ponto(pontox, pontoy);
              lista.primeiraocorrencia(p);

          }else if (sc == 6){
              System.out.println("Digite um ponto para buscar na colecao: ");
              System.out.println(lista.distanciaPonto());

          }else if (sc == 7 ){

              System.out.println("Digite o raio da circunferencia");
              input = new Scanner(System.in);
              double raio = input.nextDouble();

              System.out.println("Digite o x");
              input = new Scanner(System.in);
              int pontox = input.nextInt();
              System.out.println("Digite o y");
              input = new Scanner(System.in);
              int pontoy = input.nextInt();
              Ponto p = new Ponto(pontox, pontoy);
              System.out.println("Nova lista:"); 
              lista.circunferencia(raio, p);

          }else if (sc == 8){
            break;
          }else {
              System.out.println("Erro! Digite novamente por gentileza \n");
          }
      lista.imprimeLista();    
      }
  }
}
