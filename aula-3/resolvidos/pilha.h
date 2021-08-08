#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int topo; 
  int tam; 
  int *vetor; 
} Pilha;


Pilha* create_stack (int tam);

Pilha* reverse_stack (Pilha *original);

void print_stack(Pilha *p);

void push (Pilha *p, int elem);

int pop (Pilha *p);

int empty_stack (Pilha *p);

int full_stack (Pilha *p);

void destroy_stack (Pilha *p);
