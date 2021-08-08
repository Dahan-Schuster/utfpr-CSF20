#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   if (d != NULL) {
      // se o deck não estiver vazio, retorna os dados do primeiro elemento
      return d->p;
   }

   // caso contrário, retorna as coordenadas do centro
   return (Point) {0, 0};
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   if (d == NULL) {
      // se o deck estiver vazio, retorna as coordenadas do centro
      return (Point) {0, 0};
   } else if (d->next != NULL) {
      // caso contrário, continua procurando a cauda recursivamente
      return getRear(d->next);
   }

   // ao chegar na cauda, retorna seu ponto
   return d->p;
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   Deck *novo = (Deck *)malloc(sizeof(Deck));
   novo->next = d;
   novo->prev = NULL;
   novo->p = p;
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
   
   if (d != NULL) {
      d->prev = novo;
   }

   return novo;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   // busca recursivamente pela cauda
   if (d != NULL && d->next != NULL) {
      return insertRear(d->next, p, field);
   }

   Deck *novo = (Deck *)malloc(sizeof(Deck));
   novo->next = NULL;
   novo->prev = d;
   novo->p = p;
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
   
   if (d != NULL) {
      d->next = novo;
   }

   return d;
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   // se a lista estiver vazia, não há o que deletar
   if (d == NULL) {
      return d;
   }

   Deck *front = NULL;
   
   // se posuir um próximo elemento, conecta ele ao início da lista
   if (d->next != NULL) {
      front = d->next;
      front->prev = NULL;
   }

   // ponto eliminado agora é marcado como vazio!
   field[(d->p).x][(d->p).y] = ' ';

   // desaloca o ponto atual
   free(d);

   return front;
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   // se a lista estiver vazia, não há o que deletar
   Deck *rear = d;

   if (d != NULL) {
      // busca recursivamente pela cauda
      if (rear->next != NULL) {
         return deleteRear(rear->next, field);
      }

      // se posuir um elemento anterior, conecta ele à cauda da lista
      if (rear->prev != NULL) {
         rear->prev->next = NULL;
      }

      // ponto eliminado agora é marcado como vazio!
      field[(rear->p).x][(rear->p).y] = ' ';

      // desaloca a causa
      free(rear);
   }

   return d;
}


