#include "grafo.h"

/*Função principal.*/
int main () {

   int V = 5; /*Número de vértices*/

   Grafo* G = criar_grafo (V);

   adicionar_aresta (0, 4, G);
   adicionar_aresta (0, 1, G);
   adicionar_aresta (1, 4, G);
   adicionar_aresta (1, 3, G);
   adicionar_aresta (1, 2, G);
   adicionar_aresta (2, 3, G);
   adicionar_aresta (3, 4, G);

   imprimir_grafo (G);

   printf("# vertices = %d, # arestas = %d\n", G->V, G->E);

   destruir_grafo (G);      

   return 0;
}

