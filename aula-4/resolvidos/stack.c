#include "stack.h"
#include <limits.h>

/*Função para criar uma pilha vazia (não criar nenhum nó, só devolver NULL)!*/
Stack* create_stack () {
   return NULL;
}

/*Função para liberar uma pilha nó por nó*/
void free_stack (Stack *s) {
   Stack* aux;
   while (s != NULL) { // enquanto não chegou no fim da lista...
      aux = s->next; // guarda o endereço do próximo espaço antes de usar free
      free(s);       // libera o espaço de memória apontado por s
      s = aux;       // faz s apontar para o próximo espaço de memória
   }
}

/*Função para empilhar um elemento (inserir na cabeça da lista encadeada)!*/
Stack* push (Stack *s, int elem) {
   // aloca espaço para o novo nó
   Stack* new = (Stack*) malloc (sizeof(Stack));
   
   // inicializa o nó
   new->next = s;    // define o novo nó como primeiro da lista
   new->info = elem; // guarda a informação do nó

   // retorna o novo nó como início da lista
   return new;
}

/*Função para desempilhar um elemento (remover da cabeça da lista encadeada)!*/
Stack* pop (Stack *s) {
   // define o novo início como o próximo ítem da lista
   Stack* head = s->next;

   // destrói o antigo início
   free(s);

   // retorna o novo início
   return head;
}

/*Função para retornar o elemento no topo da pilha (cabeça da lista encadeada) sem desempilhar!*/
int top (Stack *s) {
   if (!empty_stack(s))
      return s->info; // retorna a informação guardada no início da lista
   else
      return INT_MIN;
}

/*Função para testar se uma pilha está vazia!*/
int empty_stack (Stack *s) {
   // uma pilha está vazia quando seu único elemento tem valor NULL
   return s == NULL;
}
