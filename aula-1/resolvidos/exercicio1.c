#include <stdio.h>
#include <stdlib.h>

/*NAO USE VARIAVEIS GLOBAIS!!!!!!!!!!!!!*/

/**
 * Função para enfileirar um dado elemento em um vetor
 */
void enqueue (int vetor[], int elemento, int *fim, int inicio, int tamanho)
{
    // calcula o índice real do fim da fila
    int idx_fim = *fim % tamanho;

    // calcula quantos espacos da fila foram ocupados
    int espacos_ocupados = (*fim) - inicio;
   
    if (espacos_ocupados < tamanho) {
        vetor[idx_fim] = elemento;
        (*fim)++;
    } else { // fila cheia
        printf("Fila cheia!\n");
    }
}

/**
 * Função para desenfileirar um dado elemento em um vetor
 */
int dequeue (int vetor[], int fim, int *inicio, int tamanho)
{ 
    // calcula o índice real do início da fila
    int idx_inicio = *inicio % tamanho;

    // calcula quantos espacos da fila foram ocupados
    int espacos_ocupados = fim - (*inicio);
    
    if (espacos_ocupados > 0) {
        (*inicio)++;
        return vetor[idx_inicio];
    } else { // fila vazia
        printf("Fila vazia!\n");
    }
}	

/**
 * Os valores inicio e fim são incrementados sem limite,
 * assim é possível saber a quantidade de ítens na fila
 * está dentro do permitido a partir da diferença: fim - inicio
 * Esta diferença representa a quantidade de espaços ocupados
 *
 * Para buscar o índice correspondente dos valores fim
 * e inicio (uma vez que estes crescem sem limite), é
 * só pegar o resto da divisão deles pelo tamanho da fila
 */
int main () {

   int elem;

   /*Determinando o tamanho da fila!*/ 
   int fila_tamanho = 10;
   int ini = 0;
   int fim = 0;

   /*Reservando o espaco para o vetor na memoria!*/ 
   int *fila = (int *)malloc(fila_tamanho * sizeof(int)); 

   /*Tentando inserir o elemento 1 na fila!*/ 
   elem = 1; 
   enqueue (fila, elem, &fim, ini, fila_tamanho);

   /*Tentando inserir o elemento 2 na fila!*/ 
   elem = 2; 
   enqueue (fila, elem, &fim, ini, fila_tamanho);

   /*Tentando inserir o elemento 3 na fila!*/ 
   elem = 3; 
   enqueue (fila, elem, &fim, ini, fila_tamanho);

   /*Tentando inserir o elemento 4 na fila!*/ 
   elem = 4; 
   enqueue (fila, elem, &fim, ini, fila_tamanho);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/ 
   printf("%d\n", dequeue (fila, fim, &ini, fila_tamanho));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/ 
   printf("%d\n", dequeue (fila, fim, &ini, fila_tamanho));

   free(fila);

   return 0;	 
}

