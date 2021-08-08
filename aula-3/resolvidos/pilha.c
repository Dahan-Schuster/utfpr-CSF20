#include <stdio.h>
#include "pilha.h"

/*Função para criar uma pilha!*/
Pilha* create_stack (int tam) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  return p;
}

/* Função para inverter uma pilha */
Pilha* reverse_stack (Pilha *original) {
    Pilha *reverse = create_stack (original->tam);
   
    int aux;
    while (!empty_stack(original))  {
       push (reverse, pop (original) );
    }
    
    destroy_stack (original);   
    return reverse;
}

/*Função para empilhar um elemento!*/
void push (Pilha *p, int elem) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop (Pilha *p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
  return p->vetor[p->topo];
}

/*Funão para testar se a pilha está vazia!*/
int empty_stack (Pilha *p) {
  return (p->topo ==  0);
}

/*Funão para imprimir uma pilha */
void print_stack(Pilha *p) {
  int i;
  for (i = p->topo - 1; i >= 0; i--)
    printf("%d ", p->vetor[i]);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack (Pilha *p) {
  return (p->topo == p->tam);
}

/*Função para liberar a memória alocada.*/
void destroy_stack (Pilha *p) {
  free(p->vetor);
  free(p);
}

