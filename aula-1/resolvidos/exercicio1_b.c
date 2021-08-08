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
	return 0;
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

   int elem, op;

   /*Determinando o tamanho da fila!*/ 
   int fila_tamanho = 4;
   int ini = 0;
   int fim = 0;

   /*Reservando o espaco para o vetor na memoria!*/ 
   int *fila = (int *)malloc(fila_tamanho * sizeof(int)); 
   
   printf("OP: ");
   scanf("%d", &op);

   while (op) {
	if (op == 1) {
	   printf("EL: ");
	   scanf("%d", &elem);
	   enqueue(fila, elem, &fim, ini, fila_tamanho);
	} else if (op == 2) {
	   printf("%d\n", dequeue (fila, fim, &ini, fila_tamanho));
	}

	printf("OP: ");
	scanf("%d", &op);
   }

   free(fila);
   return 0;	 
}

