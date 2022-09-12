/*
 * REPRESENTACAO DE GRAFOS - Versao 2020/2
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

#define _BRANCO_  0
#define _CINZA_   1
#define _PRETO_   2


/*
 * Estrutura de dados para representar grafos
 */
typedef struct a{ /* Celula de uma lista de arestas */
	int    nome;
	struct a *prox;
}Aresta;

typedef struct vert{  /* Cada vertice tem um ponteiro para uma lista de arestas incidentes nele */
	int nome;
	int dist;
	int cor;
	Aresta *prim;
}Vertice;

/*
 * Declaracoes das funcoes para manipulacao de grafos
 */
void criaGrafo(Vertice **G, int ordem);
void destroiGrafo(Vertice **G, int ordem);
int  acrescentaAresta(Vertice G[], int ordem, int v1, int v2);
int  calculaTamanho(Vertice G[], int ordem);
void imprimeGrafo(Vertice G[], int ordem);

/* Novas funções: */
int *calculaDistancia(Vertice G[], int ordem, int vi);

/*
 * Implementacao das funcoes para manipulacao de grafos
 */

/*
 * Criacao de um grafo com ordem predefinida (passada como argumento),
 *   e, inicilamente, sem nenhuma aresta
 */
void criaGrafo(Vertice **G, int ordem){
	int i;
	*G= (Vertice*) malloc(sizeof(Vertice)*ordem); /* Alcaçao dinamica de um vetor de vertices */

	for(i=0; i<ordem; i++){
		(*G)[i].nome= i;
		(*G)[i].dist= -1;      /* representa INFINITO */
		(*G)[i].cor= _BRANCO_; /* representa nao manipulado*/
		(*G)[i].prim= NULL;    /* Cada vertice sem nenua aresta incidente */
	}
}

/*
 * Deasaloca a memoria dinamica usada para armazenar um grafo.
 */
void destroiGrafo(Vertice **G, int ordem){
	int i;
  Aresta *a, *n;

	for(i=0; i<ordem; i++){ /* Remove lista de adjacencia de cada vértice */
	  a= (*G)[i].prim;
    while (a!= NULL){
      n= a->prox;
      free(a);
      a= n;
    }
	}
  free(*G);
}

/*
 * Acrescenta uma nova aresta em um grafo previamente criado.
 *   Devem ser passados os extremos v1 e v2 da aresta a ser acrescentada
 * Como o grafo não é orientado, para uma aresta com extremos i e j
 *   serão criadas, na estrutura de dados, arestas (i,j) e (j,i)
 */
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2){
    Aresta * A1, *A2;

	if (v1<0 || v1 >= ordem) /* Testo se vértices sao validos */
	   return 0;
	if (v2<0 || v2 >= ordem)
	   return 0;

	/* Acrescento aresta na lista do vertice v1 */
	A1= (Aresta *) malloc(sizeof(Aresta));
	A1->nome= v2;
	A1->prox= G[v1].prim;
	G[v1].prim= A1;

	/* Acrescento aresta na lista do vertice v2 se v2 != v1 */
	if (v1 == v2) return 1;

	A2= (Aresta *) malloc(sizeof(Aresta));
	A2->nome= v1;
	A2->prox= G[v2].prim;
	G[v2].prim= A2;

	return 1;
}

/*
 * Funcao que retorna o tamanho de um grafo
 */
int  calculaTamanho(Vertice G[], int ordem){
	int i;
	int totalArestas=0;

	for (i=0; i<ordem; i++){
		int j;
		Aresta *aux= G[i].prim;
		for(j=0; aux != NULL; aux= aux->prox, j++)
        if (aux->nome == i) j++; /* laco "conta em dobro" */
		totalArestas += j;
	}
	return totalArestas/2 + ordem;
}

/*
 * Imprime um grafo com uma notação similar a uma lista de adjacência.
 */
void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;
	char * cores[]= { "BRANCO", "CINZA " , "PRETO " };

	printf("\nOrdem:   %d",ordem);
	printf("\nTamanho: %d",calculaTamanho(G, ordem));
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d (Distancia:%2d  Cor:%s): ", i, G[i].dist, cores[G[i].cor]);
		aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

/*
 * Função auxiliar que recebe um grafo como argumento e
 *   um dado vertice e retorna o grau do vértice.
 */
int calculaGrauVertice(Vertice G[], int ordem, int v){
     /* Exercicio */
    if (v < 0 || v >= ordem) {
        return -1;
    }

    int j;
    Aresta *aux = G[v].prim;
    for (j = 0;aux != NULL;aux = aux->prox, j++) {
        if (aux->nome == v) j++;
    }
    return j;
}

/**
 * Calcula as distancias a partir de um vertice vi.
 */
int *calculaDistancia(Vertice G[], int ordem, int vi) {
  /* Passo 1  zero todos os dists*/
  int *dist = malloc(ordem*sizeof(int));
  int i = 0;  
  for (;i < ordem;i++) {
    dist[i] = -1;
  }
  dist[vi] = 0;

  /* Passo 2 */
  int d = 0;

  /* Passo 3 */
  int j = 0;
  /* Iterando para cada vertice do grafo */
  for (;j < ordem;j++) {
    /* Verifica se a distancia do vertice atual(j) e igual a d. */
    if (dist[j] == d) {
      /* Pega a aresta do vertice atual */
      Aresta *aux = G[j].prim;
      /* Itera sobre todas as arestas do vertice atual para pegar os vertices
        adjacentes */
    	for(; aux != NULL; aux = aux->prox) {
        if (dist[aux->nome] == -1) {
          dist[aux->nome] = d + 1;
        }
      }
      d++;
    }
  }

  return dist;
}

/**
 * Verifica se o grafo e conexo.
 */
int ehConexo(Vertice G[], int ordem) {
  int *distancias = calculaDistancia(G, ordem, 0);
  int i = 0;
  for (;i < ordem;i++) {
    if (distancias[i] == -1) {
      return 0;
    }
  }
  return 1;
}

/*
 * Programinha simples para testar a representacao de grafo
 */
int main(int argc, char *argv[]) {
	Vertice *G;
	int ordemG= 6;

	criaGrafo(&G, ordemG);
	/* acrescentaAresta(G,ordemG,0,0); */
	acrescentaAresta(G,ordemG,3,4);
	acrescentaAresta(G,ordemG,1,5);
	acrescentaAresta(G,ordemG,4,3);
	acrescentaAresta(G,ordemG,4,2);
	acrescentaAresta(G,ordemG,5,4);
	acrescentaAresta(G,ordemG,2,3);
	acrescentaAresta(G,ordemG,3,0);

	imprimeGrafo(G, ordemG);

  int *distancia = calculaDistancia(G, ordemG, 3);
  printf("Distancias:\n");
  int i = 0;
  for (;i < ordemG;i++) {
    printf("%d ", distancia[i]);
  }
  puts("\n");

  printf("E conexo? %d\n", ehConexo(G, ordemG));

	destroiGrafo(&G, ordemG);
  
	return 0;
}
