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
    int idx_fim = fila->fim % fila->tam;
    int espacos_ocupados = fila->fim - fila->ini;

    if (espacos_ocupados < fila->tam) {
        fila->vetor[idx_fim] = elemento;
        fila->fim++;
    } else {
        printf("Fila cheia!\n");
    }
}

int dequeue (Fila *fila) {
    int idx_ini = fila->ini % fila->tam;
    int espacos_ocupados = fila->fim - fila->ini;

    if (espacos_ocupados > 0) {
        fila->ini++;
        return fila->vetor[idx_ini];
    } else {
        printf("Fila vazia!\n");
        return 0;
    }
}       

int main () {
    int elem, op;

    /*Determinando o tamanho da fila!*/ 
    int fila_tamanho = 4;
    Fila *fila = criar_fila(fila_tamanho);

    printf("OP: ");
    scanf("%d", &op);

    while (op) {
        if (op == 1) {
	    printf("EL: ");
	    scanf("%d", &elem);
	    enqueue(fila, elem);
        } else if (op == 2) {
	    printf("%d\n", dequeue (fila));
	}

	printf("OP: ");
	scanf("%d", &op);
    }

    free(fila);
    return 0;
}
