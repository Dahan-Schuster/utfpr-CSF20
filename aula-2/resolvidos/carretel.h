#include "queue.h"

#ifndef __CARRETEL__
#define __CARRETEL__

typedef struct _carretel {
    Fila *fila;
    int numero_sorteado;
} Carretel;


/** Instancia e retorna um novo carretel */
Carretel *criar_carretel();

/** Gira o carretel um número n de vezes e retorna o número sorteado */
int girar_carretel(Carretel *c);

#endif
