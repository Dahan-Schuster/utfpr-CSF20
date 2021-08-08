#include <stdlib.h>

#include "carretel.h"
#include "queue.h"

#define TAM 9
#define LIMITE_VOLTAS TAM * 5

/**
 * Move os elementos da fila para a esquerda por um
 * número aleatório de vezes, com limite de voltas completas
 * igual a LIMITE_VOLTAS
 */
int girar_carretel(Carretel *c)
{    
    // gera um número aleatório representando os giros
    int qte_giros = rand() % (LIMITE_VOLTAS) + 1;

    // variáveis utilizadas no loop
    int i, e;

    // irá mover um elemento por giro
    for (i = 0; i < qte_giros; i++) {
        e = dequeue(c->fila); // remove o primeiro elemento da fila...
        enqueue(c->fila, e);  // e o põe de volta no final dela
    }

    c->numero_sorteado = primeiro_elemento(c->fila);

    return c->numero_sorteado;
}

/**
 * Cria e retorna uma fila de TAM elementos
 * inicializada com todos os elementos valendo índice + 1
 */
Carretel *criar_carretel()
{
    Carretel *carretel = (Carretel *) malloc(sizeof(Carretel));

    // cria uma fila comum com 10 posições, uma sendo
    // sacrificada para indicar que a fila está cheia
    Fila *fila = create_queue(TAM + 1);

    // preenche a fila com números de 1 a TAM
    for (int i = 0; i < TAM; i++)
        enqueue(fila, i + 1);

    carretel->fila = fila;
    
    // retorna o carretel criado
    return carretel;
}

void free_carretel (Carretel *c)
{
    free_queue (c->fila);
    free (c);
}
