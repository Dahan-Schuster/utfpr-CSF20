#include "lista.h"

/*Programa de teste.*/
int main () {

   int i;

   Lista *lista = criar_lista ();

   for (i = 0; i < 5; i++) {
      lista = inserir (lista, i);
   }

   for (i = 10; i >= 5; i--) {
      lista = inserir (lista, i);
   }

   printf("Lista: ");
   imprimir_lista (lista);
   printf("\n");

   printf("Número de nós na lista (itr): %d\n", conta_nos_itr(lista));
   printf("Número de nós na lista (rec): %d\n", conta_nos_rec(lista));

   printf("Posição de %d na lista (itr): %d\n", 7, procura_itr(lista, 7));
   printf("Posição de %d na lista (rec): %d\n", 7, procura_rec(lista, 7));

   printf("Posição de %d na lista (itr): %d\n", 15, procura_itr(lista, 15));
   printf("Posição de %d na lista (rec): %d\n", 15, procura_rec(lista, 15));
   
   printf("Maior elemento na lista (itr): %d\n", lista_max_itr(lista));
   printf("Maior elemento na lista (rec): %d\n", lista_max_rec(lista));
   
   printf("Soma total dos elementos na lista (itr): %d\n", lista_soma_itr(lista));
   printf("Soma total dos elementos na lista (rec): %d\n", lista_soma_rec(lista));

   printf("Lista invertida (itr): ");
   imprimir_invertida_itr (lista);
   printf("\n");

   printf("Lista invertida (rec): ");
   imprimir_invertida_rec (lista);
   printf("\n");

   destruir_lista (lista);

   return 0;
}

