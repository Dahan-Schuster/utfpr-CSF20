#include "grafo.h"


/*Função para criar um grafo representado como uma lista de adjacências com {V} vértices de tamanho.*/
Grafo* criar_grafo (int V) {
   Grafo *g = (Grafo *) malloc(sizeof(Grafo));
   
   g->E = 0; // número de arestas do grafo, começa com 0
   g->V = V; // número de vértices do grafo, predefinido na inicialização
   g->list = (No **)malloc(V * sizeof(No)); // array de listas de adjacência
   int i;
   for (i = 0; i < V; i++) {
      g->list[i] = NULL;
   }

   return g;
}

/*Função para desalocar uma lista de adjacências*/
void destruir_lista (No *n) {
  No *aux;
  while (n != NULL) {
    aux = n->next;
    free(n);
    n = aux;
  }
}

/*Função para destruir um grafo construído através de uma representação por lista de adjacências.*/
void destruir_grafo (Grafo *G) {
   if (G != NULL) {
      int i;
      // destrói cada lista antes de destruir o grafo
      for (i = 0; i < G->V; i++)
         destruir_lista((G->list)[i]);
      free(G->list);
      free(G);
   }
}

/* Função para imprimir uma lista de adjacências de forma recursiva */
void imprimir_lista (No* lista) {
   if (lista != NULL) {
      printf("%d ", lista->id);
      imprimir_lista(lista->next);
   }
}

/*Função para imprimir um grafo construído através de uma representação por lista de adjacências.*/
void imprimir_grafo (Grafo *G) {
   // verifica se {G} é nulo antes de verificar suas informações
   if (G != NULL) {
      int i;
      for (i = 0; i < G->V; i++) {
         printf("%d -> ", i);
         imprimir_lista((G->list)[i]);
         printf("\n");
      }
   }
}

/* Função para verificar se um valor {v} representa um vértice válido de {G} */
int vertice_valido (int v, Grafo *G) {
   // o vértice é válido se seu valor estiver
   // entre 0 e o número de vértices do grafo
   // também verifica se {G} é nulo antes de acessar suas informações
   return G != NULL && (v >= 0 && v <= G->V);
}

/* Função para criar um novo nó com valor {id} e adicioná-lo no início da lista */
No* novo_no(No *lista, int id) {
   No *novo =(No*)malloc(sizeof(No));
   novo->id = id;
   novo->next = lista;
   return novo;
}

/*Função para adicionar a aresta (ligação) entre os vértices {u,v} e {v,u} no grafo {G}.*/
/*Adicione um novo vértice sempre no início da lista encadeada do respectivo vértice.*/
/*Você pode dividir essa função em duas se achar necessário!*/
void adicionar_aresta (int u, int v, Grafo *G) {
   // verifica se {G} é nulo antes de verificar suas informações
   if (G != NULL) {
      if (vertice_valido(u, G) && vertice_valido(v, G)) {
         // adiciona {v} à lista de adjacência de {u} e vice-versa
         (G->list)[u] = novo_no((G->list)[u], v);
         (G->list)[v] = novo_no((G->list)[v], u);
         // incrementa o número de arestas do grafo em 1
         G->E++;
      } else {
         printf("Vértices inválidos!\n");
      }
   } else {
      printf("Grafo não inicializado!\n");
   }
}