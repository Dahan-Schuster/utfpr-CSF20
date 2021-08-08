#include <stdio.h>
#include <stdlib.h>

#ifndef __QUEUE__
#define __QUEUE__

typedef struct fila {
   int ini; /*guarda o inicio da fila*/
   int fim; /*guarda o fim da fila*/
   int tam; /*tamanho da fila*/
   int *vetor; /*vetor de elementos inteiros*/
} Fila;

Fila* create_queue (int tam);

int primeiro_elemento (Fila *f);

void enqueue (Fila *f, int e);

int dequeue (Fila *f);

int empty (Fila *f);

int full (Fila *f);

void free_queue (Fila *f);

#endif

