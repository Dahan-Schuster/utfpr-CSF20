#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 25

typedef struct {
  int x;
  int y;
} Point;

typedef struct deck {
  Point p;
  struct deck *next;
  struct deck *prev;
} Deck;

/*Cria um deck vazio.*/
Deck* createDeck ();

/*Adiciona um item na cabeça da lista.*/
Deck* insertFront (Deck *q, Point p, char field[][SIZE]);  

/*Adiciona um item na cauda da lista.*/
Deck* insertRear (Deck *q, Point p, char field[][SIZE]);  

/*Remove um item da cabeça da lista.*/
Deck* deleteFront (Deck *q, char field[][SIZE]);          

/*Remove um item da cauda da lista.*/
Deck* deleteRear (Deck *q, char field[][SIZE]);           

/*Retorna sem remover o item na cabeça da lista.*/
Point getFront (Deck *q);                                 

/*Retorna sem remover o item na cauda da lista.*/
Point getRear (Deck *q);                                  

