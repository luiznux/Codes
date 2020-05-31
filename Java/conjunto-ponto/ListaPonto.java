/*
Entrega da prova 1 - Paradigmas de Linguagens de Programação – 05N

Nós,

Bruno Severo Camilo - 41781619
Luiz Fernando - 31861806

declaramos que

todas as respostas são fruto de nosso próprio trabalho, não copiamos respostas de colegas externos à equipe, não disponibilizamos nossas respostas para colegas externos ao grupo e não realizamos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/

/* Classe ListaPonto */

import java.lang.Math;

public class ListaPonto{
  private Ponto pontos[]; 
  private int validos; 
 
  
  /* Construtor */
  public ListaPonto(int n){ 
    this.pontos = new Ponto[n];
    this.validos = 0;
  }


  public boolean isFull(){
    return (this.pontos.length == this.validos);
  }


  public boolean isNull(int ind){
    return (this.pontos[ind] == null);
  }


  public int getValido(){
    return this.validos;
  }


  public void empurraDireita(int ind){
    for(int i = this.validos; i > ind ; i--){
      this.pontos[i] = this.pontos[i-1];
    }
    
  }


  public void empurraEsquerda(int ind){
    for(int i = ind ; i < this.validos; i++)
    {
      this.pontos[i] = this.pontos[i+1];
    }
    this.pontos[validos] = null;
  }


  public void imprimeLista()
  {
    System.out.print("[ ");
    for(int i = 0; i < this.validos; i++){
      if(this.pontos[i] == null)
        System.out.print("0 ");
      else
        System.out.print(this.pontos[i]+" ");
    }
    System.out.println("]");
  }



  
   /*1*/
  public boolean adicionaFinal(Ponto p){
    if(isFull())
    {
      System.out.println("A lista de pontos está cheia");
      return false;
    }
    this.pontos[this.validos] = p;
    this.validos += 1;
    return true;
  }


  /*2*/
  public void adicionaColecao(Ponto p, int ind)
  {
    //verifica indice valido
    if(ind < 0 || ind >= pontos.length)
      System.out.println("Indice Inválido!");
    else if(isFull())
    {
      System.out.println("A lista de pontos está cheia");
      return;
    }
    else
    {
      //caso queira inserir na posição nula
      if(isNull(ind))
      {
        adicionaFinal(p);
        System.out.println("Foi adicionado com sucesso sem alteração");
        this.validos += 1;
      }
      else
      {
        empurraDireita(ind);
        this.pontos[ind] = p;
        System.out.println("Adicionado com shift");
        this.validos += 1;
      }
    
    }
  }


  /*3*/
  public int primeiraocorrencia(Ponto p){
    for(int i = 0; i < this.validos; i++){
      if(this.pontos[i] == p)
        return i;
    }
    return -1;
  }


  /*4*/
  public void removePonto(int ind){
    if(ind == (validos-1))
      this.pontos[this.validos] = null;
    if(!isNull(ind+1)){
      empurraEsquerda(ind);
    }
    this.validos -= 1;
  }

  /*5*/
  public double distanciaPonto(){
    double distancia = 0;
    for (int i = 0; i < this.validos; i++){
      for (int j = 0; j < this.validos; j++){
        double result = this.pontos[i].distancia(pontos[j]);
        if (result > distancia)
          distancia = result;
      }
    }
    return distancia;
  }
  /*6*/
  public ListaPonto circunferencia(double raio,Ponto centro){
    ListaPonto pontosCircun = new ListaPonto(this.pontos.length);
    for (int i = 0; i < this.validos; i++){
      if(this.pontos[i].distancia(centro) <= raio){
        pontosCircun.adicionaFinal(this.pontos[i]);
      }
    }
    pontosCircun.imprimeLista();
    return pontosCircun;
  }
}