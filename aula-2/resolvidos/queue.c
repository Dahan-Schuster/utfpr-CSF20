#include "queue.h"

Fila* create_queue (int tam) {
   Fila *f = (Fila *)malloc(sizeof(Fila));
   f->ini = 0;
   f->fim = 0;
   f->tam = tam;
   f->vetor = (int*)malloc(tam*sizeof(int));
   return f;
}

/**
 * Retorna o primeiro elemento do fila, sem o desenfileirar
 */
int primeiro_elemento (Fila *f) {
    return f->vetor[f->ini];
}

/*Função para enfileirar um elemento de uma fila 
  circular implementada através de um vetor!*/
void enqueue (Fila *f, int e) {
   if (full(f)) {
      printf("fila cheia!");
      exit(1); /*aborta programa*/
   }

   f->vetor[f->fim] = e;           /*insere elemento*/
   f->fim = (f->fim + 1) % f->tam; /*incremento*/
}

/*Função para desenfileirar um elemento de uma fila 
  circular implementada através de um vetor!*/
int dequeue (Fila *f) {
   if (empty(f)) {
      printf("fila vazia!");
      exit(1); /*aborta programa*/
   }

   int e = f->vetor[f->ini];        /*guarda o elemento*/
   f->ini = (f->ini + 1) % f->tam;  /*incremento*/
   return e;                        /*retorna elemento*/
}

int empty (Fila *f) {
   return (f->ini == f->fim);
}

int full (Fila *f) {
   return (f->ini == ((f->fim + 1) % f->tam));
}

void free_queue (Fila *f) {
   free(f->vetor);
   free(f);
}




