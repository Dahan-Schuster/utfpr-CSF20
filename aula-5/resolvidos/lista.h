#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
   int info;
   struct _no *next;
} Lista;

int conta_nos_itr (Lista* lista);

int conta_nos_rec (Lista* lista);

int procura_itr (Lista* lista, int elemento);

int procura_rec (Lista* lista, int elemento);

int lista_max_itr (Lista* lista);

int lista_max_rec (Lista* lista);

int lista_soma_itr (Lista* lista);

int lista_soma_rec (Lista* lista);

void imprimir_invertida_itr (Lista* lista);

void imprimir_invertida_rec (Lista* lista);

Lista* criar_lista (void);

Lista* inserir (Lista *lista, int elem);

void imprimir_lista (Lista *lista);

void destruir_lista (Lista *l);

