#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int ini;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int tamanho) {
    Fila *fila;
    fila = (Fila *) malloc(sizeof(Fila));

    fila->ini = 0;
    fila->fim = 0;
    fila->tam = tamanho;
    fila->vetor = (int *) malloc(tamanho * sizeof(int));
}

void destruir_fila (Fila *f) {
    free(f->vetor);
    free(f);
}

void enqueue (Fila *fila, int elemento) {
    // calcula o índice real do início da fila
    int idx_fim = (fila->fim+1) % fila->tam;

    // calcula quantos espacos da fila foram ocupados
    int espacos_ocupados = fila->fim - fila->ini;

    // se ainda houverem espaços na fila...
    if (espacos_ocupados < fila->tam) {
        fila->vetor[idx_fim] = elemento;    // adiciona o ítem na lista
        fila->fim++;                        // atualiza o índice do último ítem
    } else {
        printf("Fila cheia!\n");
    }
}

int dequeue (Fila *fila) {
    // calcula o índice real do início da fila
    int idx_ini = fila->ini % fila->tam;

    // calcula quantos espacos da fila foram ocupados
    int espacos_ocupados = fila->fim - fila->ini;

    // se houverem itens na fila...
    if (espacos_ocupados > 0) {
        fila->ini++;                    // atualiza o índice do próximo ítem
        return fila->vetor[idx_ini];    // retorna o primeiro ítem da lista
    } else {
        printf("Fila vazia!\n");
        return 0;
    }
}       

int main () {
   /*Inicializando a estrutura de dados fila!*/  
   Fila *fila = criar_fila (10);

   /*Tentando inserir o elemento 1 na fila!*/ 
   int elem = 1; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 2 na fila!*/ 
   elem = 2; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 3 na fila!*/ 
   elem = 3; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 4 na fila!*/ 
   elem = 4; 
   enqueue (fila, elem);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/ 
   printf("%d\n", dequeue (fila));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/ 
   printf("%d\n", dequeue (fila));

   destruir_fila (fila);

   return 0;
}
