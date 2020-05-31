import java.lang.Math;

/*
Entrega da prova 1 - Paradigmas de Linguagens de Programação – 05N

Nós,

Bruno Severo Camilo - 41781619
Luiz Fernando - 31861806

declaramos que

todas as respostas são fruto de nosso próprio trabalho, não copiamos respostas de colegas externos à equipe, não disponibilizamos nossas respostas para colegas externos ao grupo e não realizamos quaisquer outras atividades desonestas para nos beneficiar ou prejudicar outros.
*/

/* Classe ListaPonto */

/* Classe Ponto */
public class Ponto {
  private int x;   /* Ponto x */
  private int y;   /* Ponto y */

  /* Construtor */
  public Ponto(int x, int y){
    this.x = x;
    this.y = y;
  }

  public int getX(){
    return this.x;
  }

  public int getY(){
    return this.y;
  }

  
  /* Sobrescrever o metodo toString da classe pai da classe Ponto
  */
  public String toString(){
    return "{"+this.x+", "+this.y+"}";
  }

  /* Verifica se dois pontos são iguais */
  public boolean igual(Ponto p){
    return (this.x == p.x && this.y == p.y);
  }

  /* Calcula a distancia entre dois pontos: */
  /* Distancia^2 = (xb-xa)^2 + (yb-ya)^2    */
  public double distancia(Ponto p){
    double dx = Math.pow((p.x - this.x), 2);
    double dy = Math.pow((p.y - this.y), 2);
    return Math.sqrt((dx+dy));
  }
}