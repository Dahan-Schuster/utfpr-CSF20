#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int info;
  struct queue *next;
} Queue;

Queue* create_queue ();

void free_queue (Queue *q);

Queue* enqueue (Queue *q, int elem);

Queue* dequeue (Queue *q);

int front (Queue *q);

int empty_queue (Queue *q);

int sizeof_queue (Queue *q);

