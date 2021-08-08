#include "queue.h"
#include <limits.h>


/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
Queue* create_queue () {
   return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_queue (Queue *q) {
   Queue* aux;
   while (q != NULL) { // enquanto não chegou no fim da lista...
      aux = q->next;   // guarda o endereço do próximo espaço antes de usar free
      free(q);         // libera o espaço de memória apontado por s
      q = aux;         // faz s apontar para o próximo espaço de memória
   }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
Queue* enqueue (Queue *q, int elem) {
   // aloca espaço para o novo nó
   Queue* new = (Queue*) malloc (sizeof(Queue));
   

   // inicializa o nó
   new->info = elem;
   new->next = NULL;

   
   // se a fila estiver vazia...
   if (empty_queue (q)) {
      // define o novo nó como a cabeça da fila
      q = new;

   // se a fila tiver elementos...
   } else {

      // encontra o último nó para inserir o novo nó após ele
      Queue* end = q;
      while (end->next != NULL) {
         end = end->next;
      }

      // define o novo nó como a nova cauda da lista
      end->next = new;
   }

   // retorna a própria cabeça da lista
   return q;
}

/*Função para desenfileirar um elemento (remover da cabeça da lista encadeada)!*/
Queue* dequeue (Queue *q) {
   // define o novo início como o próximo ítem da lista
   Queue* head = q->next;

   // destrói o antigo início
   free(q);

   // retorna o novo início
   return head;
}

/*Função para retornar o primeiro elemento da fila (cabeça da lista encadeada) sem desenfileirar!*/
int front (Queue *q) {
   if (q != NULL)
      return q->info; // retorna a informação guardada no início da lista
   else
      return INT_MIN;
}

/*Função para testar se uma fila está vazia!*/
int empty_queue (Queue *q) {
   // uma pilha está vazia quando seu único elemento tem valor NULL
   return q == NULL;
}

/* Função para retornar o tamanho da fila */
int sizeof_queue (Queue *q) {
   // se a fila estiver vazia, seu tamanho é 0
   if (empty_queue (q)) {
     return 0;

   // se a fila tiver elementos...
   } else {
      int i = 1; // o tamanho é no mínimo 1
      Queue* end = q;

      // incrementa o valor de i até achar o último elemento
      while (end->next != NULL) {
         end = end->next;
         i++;
      }

      // retorna i como o tamanho da fila
      return i;
   }
}

