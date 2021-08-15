#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, unsigned long int tamanho) {
  unsigned long int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

void Imprimir (int *vetor, unsigned long int tamanho) {
  unsigned long int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

void Imprimir2 (int *vetor, unsigned long int tamanho, unsigned long int inicio) {
  unsigned long int i;
  for (i = inicio; i < tamanho; i++) {
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

int organizarParticaoRandom(int *vetor, int esq, int dir) {
  trocar(vetor, dir, getRandomBetween(esq, dir));
  int pivot = vetor[dir];

  unsigned long int i = esq - 1, j;
  for (j = esq; j < dir; j++)
    if (vetor[j] <= pivot)
      trocar(vetor, ++i, j);

  trocar(vetor, ++i, dir);
  return i;
}

int organizarParticao(int *vetor, int esq, int dir) {
  int pivot = vetor[dir]; // pivot como último elemento
  unsigned long int i = esq - 1, j;

  for (j = esq; j < dir; j++)
    if (vetor[j] <= pivot)
      trocar(vetor, ++i, j);

  trocar(vetor, ++i, dir);
  return i;
}

void QuickSort (int *vetor, int esq, int dir) {
  if (esq >= dir) return;

  // int pivot = organizarParticao(vetor, esq, dir);
  int pivot = organizarParticaoRandom(vetor, esq, dir);

  QuickSort(vetor, esq, pivot - 1);
  QuickSort(vetor, pivot + 1, dir);
}

void runAndCount(int *vetor, unsigned long int tamanho, char *order) {
  clock_t start, end;
  double elapsed_time;
   
  start = clock();
  QuickSort (vetor, 0, tamanho-1);
  end = clock();
   
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (%s): %f\n", order, elapsed_time);
}

void test(int* vetor, unsigned long int tamanho, char *order) {

  // Imprimir(vetor, tamanho);
  runAndCount(vetor, tamanho, order);
  // Imprimir(vetor, tamanho);

  if (!Verifica_Ordenacao(vetor, tamanho)) {
    printf("Erro: a ordenação %s não está correta!\n", order);
  }

  printf("\n");
}

void testRandom(int *vetor, unsigned long int tamanho) {
  unsigned long int i;

  for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1);
  }

  test(vetor, tamanho, "Aleatório  ");
}

void testAsc(int *vetor, unsigned long int tamanho) {
  unsigned long int i;
  for (i = 0; i < tamanho; i++) {
      vetor[i] = i;
  }

  test(vetor, tamanho, "Crescente  ");
}

void testDesc(int *vetor, unsigned long int tamanho) {
  unsigned long int i, j = tamanho;
  for (i = 0; i < tamanho; i++) {
      vetor[i] = j;
      j--;
  }

  test(vetor, tamanho, "Decrescente");
}


/*Função principal.*/
int main (int argc, char *argv[]) {
  srand(time(NULL));
  unsigned long int tamanho = 1000;
  
  int *vetor = (int *)malloc(tamanho * sizeof(int));

  printf("Itens: %ld\n", tamanho);

  testRandom(vetor, tamanho);
  testAsc(vetor, tamanho);
  testDesc(vetor, tamanho);
  
  free (vetor);
  return 0;
}
