#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

void trocar(int *vetor, unsigned long int i, int j) {
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

int getRandomBetween(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int particionar(int *vetor, int esq, int dir, int pos) {
  int pivot = vetor[pos];

  int i = esq - 1, j;

  for (j = esq; j < dir; j++)
    if (vetor[j] < pivot)
      i++;

  return ++i;
}

int QuickFind (int *vetor, int esq, int dir, int pos) {
  int index = particionar(vetor, esq, dir, pos);
  if (index == pos) return vetor[index];

  if (index < pos) {
    index = QuickFind(vetor, index + 1, pos, pos);
  } else {
    index = QuickFind(vetor, pos, index - 1, pos);
  }

  return vetor[index];
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   
   //int tamanho = 10;
   //int *vetor = (int *)malloc(tamanho * sizeof(int));
   //for (i = 0; i < tamanho; i++) {
   //   vetor[i] = rand() % (tamanho+1);
   //}
   
   int tamanho = 8;
   int vetor[] = {7, 1, 3, 10, 17, 2, 21, 22};
   
   Imprimir (vetor, tamanho);
   start = clock();
   int pos = 4;
   printf("O elemento procurado na posição %d é %d\n", pos, QuickFind(vetor, 0, tamanho-1, pos));
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   //free (vetor);
   return 0;
}
