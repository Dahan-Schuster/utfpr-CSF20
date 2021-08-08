#include "queue.h"

/**
 * Função para "girar" a fila uma quantidade n de movimentos
 * Cada movimento equivale a mover o primeiro elemento para o fim da fila
 */
Queue* rotate_queue(Queue* q, int movimentos) {
  int i;
  for (i = 0; i < movimentos; i++) {
    // enfileira um elemento de valor igual ao do primeiro da fila
    q = enqueue (q, front (q));

    // remove o primeiro elemento da fila
    q = dequeue (q);
  }

  return q;
}

/**
 * Função para preencher toda a fila com elementos de 1 a qteElementos
 */
Queue* fill_queue(Queue* q, int qteElementos) {
  int i;
  for (i = 1; i <= qteElementos; i++) {
    // enfileira o valor de i na fila
    q = enqueue (q, i);
  }

  return q;
}

int main () {
  int n, qteCompetidores;
  
  printf("Josephus - digite o passo da morte e numero de competidores: ");
  scanf("%d %d", &n, &qteCompetidores);

  // cria a fila e a preenche com números representando cada competidor
  Queue *q = create_queue ();
  q = fill_queue (q, qteCompetidores);

  // enquanto houver mais de um competidor vivo...
  while (sizeof_queue(q) > 1) {
    // gira a fila até que o n-ésimo competidor seja o primeiro
    q = rotate_queue (q, n - 1);

    // imprime o competidor sorteado para morte
    printf("%d ", front (q));

    // remove o corpo da fila
    q = dequeue (q);
  }

  // o único elemento salvo é o sobrevivente
  printf(", sobrevivente: %d\n", front (q));
  
  free_queue (q);
  return 0;
}
