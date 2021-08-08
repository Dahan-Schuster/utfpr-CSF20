#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

/**
 *  Itens |  Tempo (s) | Comparações |      Trocas
 *     10 |   0.000005 |          45 |          26
 *    100 |   0.000088 |        4950 |        4880
 *    500 |   0.001871 |      124750 |      117520
 *   1000 |   0.008127 |      499500 |      489712
 *  10000 |   0.926698 |    49995000 |    50475118
 *  80000 |  59.200411 |  3199960000 |  3206050970
 * 100000 |  92.039109 |  4999950000 |  5007183364
 * 250000 | 573.222468 | 31249875000 | 31199716468
 */
void BubbleSort (int *vetor, int tamanho, unsigned long int *cp, unsigned long int *tr) {
  int i, j;
  int aux;
  *cp = *tr = 0;

  for (i = 0; i < tamanho + 1; i = 0, tamanho--) {
    for (j = 0; j < tamanho - 1; j++) {
       *cp += 1;
       if (vetor[j] > vetor[j+1]) {
         aux = vetor[j+1];
         vetor[j+1] = vetor[j];
         vetor[j] = aux;
         *tr += 2;
       }
    }
  }
}

/**
 *  Itens | Tempo (s) | Call Stacks | Trocas
 *     10 |  0.000005 |          55 |     26
 *    100 |  0.000454 |        5050 |   4880
 *    500 |  0.011467 |      125250 | 117520
 */
void BubbleSortRec (int *vetor, int tamanho, unsigned long int *st, unsigned long int *tr) {
  (*st)++;

  static unsigned int i = 0;
  int aux;

  if (tamanho > 1) {
    if (i < tamanho - 1) {
      if (vetor[i] > vetor[i+1]) {
        aux = vetor[i+1];
        vetor[i+1] = vetor[i];
        vetor[i] = aux;
        *tr += 2;
      }

      i++;
    } else if (i == tamanho - 1) {
      i = 0;
      tamanho--;
    }

    BubbleSortRec(vetor, tamanho, st, tr);
  }
}

/**
 *  Itens |  Tempo (s) | Comparações | Trocas
 *     10 |   0.000004 |          65 |     14
 *    100 |   0.000049 |        5150 |    190
 *    500 |   0.000886 |      125750 |    986
 *   1000 |   0.003462 |      501500 |   1976
 *  10000 |   0.323380 |    50015000 |  19968
 *  80000 |  20.777822 |  3200120000 | 159966
 * 100000 |  32.486322 |  5000150000 | 199984
 * 250000 | 203.464002 | 31250375000 | 499964
 */
void SelectionSort (int *vetor, int tamanho, unsigned long int *cp, unsigned long int* tr) {
  int i, j;
  int i_menor, menor;
  int aux;
  *cp = *tr = 0;

  for (i = 0; i < tamanho; i++) {
    menor = vetor[i];
    for (j = i; j < tamanho; j++) {
      *cp += 1;
       if (vetor[j] < menor) {
         menor = vetor[j];
         i_menor = j;
       }
    }
    
    *cp += 1;
    if (vetor[i] > menor) {
      aux = vetor[i];
      vetor[i] = menor;
      vetor[i_menor] = aux;
      *tr += 2;
    }
  }
}

/**
 *  Itens | Tempo (s) | Call Stacks | Trocas
 *     10 |  0.000005 |          66 |     10
 *    100 |  0.000149 |        5151 |    100
 *    500 |  0.004244 |      125751 |    500
 */
void SelectionSortRec (int *vetor, int tamanho, unsigned long int *st, unsigned long int* tr) {
  (*st)++;

  static unsigned int i = 0, j = 0, i_menor = 0;
  static int menor = INT_MAX;

  if (i < tamanho) {
    if (j < tamanho) {
      if (vetor[j] < menor) {
        menor = vetor[j];
        i_menor = j;
      }

      j++;
    } else if (j == tamanho) {
      if (vetor[i] > menor) {
        int aux = vetor[i];
        vetor[i] = menor;
        vetor[i_menor] = aux;
      }
        
      (*tr)++, i++, j = i, menor = INT_MAX;
    }

    SelectionSortRec(vetor, tamanho, st, tr);
  }
}

/**
 *  Itens |  Tempo (s) | Comparações |      Trocas
 *     10 |   0.000003 |          18 |          27
 *    100 |   0.000031 |        2221 |        2320
 *    500 |   0.000705 |       62791 |       63290
 *   1000 |   0.003566 |      252035 |      253034
 *  10000 |   0.269640 |    25170453 |    25180452
 *  80000 |  17.077466 |  1592274268 |  1592354267
 * 100000 |  26.575925 |  2501664785 |  2501764784
 * 250000 | 166.137181 | 15636261619 | 15636511618
 */
void InsertionSort (int *vetor, int tamanho, unsigned long int *cp, unsigned long int *tr) {
  int i, j;
  int i_key, key;
  *cp = *tr = 0;

  for (i = 1; i < tamanho; i++) {
    key = vetor[i], i_key = i;

    for (j = i - 1; j >= 0; j--, (*cp)++) {
      if (key < vetor[j]) {
        vetor[j+1] = vetor[j], i_key = j, (*tr)++;
      } else break;
    }
    
    vetor[i_key] = key, (*tr)++;
  }
}

/**
 *  Itens | Tempo (s) | Call Stacks |     Trocas
 *     10 |  0.000003 |          20 |         13
 *    100 |  0.000010 |         292 |        195
 *    500 |  0.000042 |        1478 |        988
 *   1000 |  0.000235 |        2984 |       1990
 *  10000 |  0.001605 |       29976 |      19987
 *  80000 |  0.013543 |      239968 |     159983
 */
void InsertionSortRec (int *vetor, int tamanho, unsigned long int *st, unsigned long int *tr) {
  (*st)++;

  static int i = 1, j = 0, i_key = 1;
  static int key;

  if (i < tamanho) {
    key = vetor[i];

    if (j >= 0) {
      if (key < vetor[j]) {
        vetor[j+1] = vetor[j], (*tr)++;
      
        i_key = j, j--;
        InsertionSortRec(vetor, tamanho, st, tr);
      } else
          vetor[i_key] = key, (*tr)++;
    }
    
    i++, i_key = i, j = i - 1;
    InsertionSortRec(vetor, tamanho, st, tr);
  }
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}

void testBubble(int *vetor, int tamanho) {
  clock_t start, end;
  double elapsed_time;
  unsigned long int cp, tr;

  start = clock();
  // Imprimir(vetor, tamanho);
  BubbleSort (vetor, tamanho, &cp, &tr);
  // Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  
  printf("Tempo de execução (BubbleSort): %f | Comparações: %ld | Trocas: %ld\n", elapsed_time, cp, tr);

  if (!Verifica_Ordenacao(vetor, tamanho)) {
     printf("Erro: a ordenação do BubbleSort não está correta!\n");
  }
}

void testBubbleRec(int *vetor, int tamanho) {
  clock_t start, end;
  double elapsed_time;
  unsigned long int st = 0, tr = 0;

  start = clock();
  // Imprimir(vetor, tamanho);
  BubbleSortRec (vetor, tamanho, &st, &tr);
  // Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  
  printf("Tempo de execução (BubbleSortRec): %f | Call Stacks: %ld | Trocas: %ld\n", elapsed_time, st, tr);

  if (!Verifica_Ordenacao(vetor, tamanho)) {
     printf("Erro: a ordenação do BubbleSortRec não está correta!\n");
  }
}

void testSelection(int *vetor, int tamanho) {
  clock_t start, end;
  double elapsed_time;
  unsigned long int cp, tr;

  start = clock();
  // Imprimir(vetor, tamanho);
  SelectionSort (vetor, tamanho, &cp, &tr);
  // Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSort): %f | Comparações: %ld | Trocas: %ld\n", elapsed_time, cp, tr);
  if (!Verifica_Ordenacao(vetor, tamanho)) {
     printf("Erro: a ordenação do SelectionSort não está correta!\n");
  }
}

void testSelectionRec(int *vetor, int tamanho) {
  clock_t start, end;
  double elapsed_time;
  unsigned long int st = 0, tr = 0;

  start = clock();
  // Imprimir(vetor, tamanho);
  SelectionSortRec (vetor, tamanho, &st, &tr);
  // Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSortRec): %f | Call Stacks: %ld | Trocas: %ld\n", elapsed_time, st, tr);
  if (!Verifica_Ordenacao(vetor, tamanho)) {
     printf("Erro: a ordenação do SelectionSortRec não está correta!\n");
  }
}

void testInsertion(int *vetor, int tamanho) {
  clock_t start, end;
  double elapsed_time;
  unsigned long int cp, tr;

  start = clock();
  // Imprimir(vetor, tamanho);
  InsertionSort (vetor, tamanho, &cp, &tr);
  // Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (InsertionSort): %f | Comparações: %ld | Trocas: %ld\n", elapsed_time, cp, tr);
  if (!Verifica_Ordenacao(vetor, tamanho)) {
     printf("Erro: a ordenação do InsertionSort não está correta!\n");
  }

}

void testInsertionRec(int *vetor, int tamanho) {
  clock_t start, end;
  double elapsed_time;
  unsigned long int st = 0, tr = 0;

  start = clock();
  // Imprimir(vetor, tamanho);
  InsertionSortRec (vetor, tamanho, &st, &tr);
  // Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (InsertionSortRec): %f | Call Stacks: %ld | Trocas: %ld\n", elapsed_time, st, tr);
  if (!Verifica_Ordenacao(vetor, tamanho)) {
     printf("Erro: a ordenação do InsertionSortRec não está correta!\n");
  }
}

int main () {
  srand(time(NULL));

  int i;
  int tamanho = 500;

  int *vBubble1 = (int *)malloc(tamanho * sizeof(int));
  int *vSelect1 = (int *)malloc(tamanho * sizeof(int));
  int *vInsert1 = (int *)malloc(tamanho * sizeof(int));

  int *vBubble2 = (int *)malloc(tamanho * sizeof(int));
  int *vSelect2 = (int *)malloc(tamanho * sizeof(int));
  int *vInsert2 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     vBubble1[i] = vBubble2[i] = rand() % (tamanho+1);
     vSelect1[i] = vSelect2[i] = rand() % (tamanho+1);
     vInsert1[i] = vInsert2[i] = rand() % (tamanho+1);
  }

  printf("Itens: %d\n\n", tamanho);

  testBubble(vBubble1, tamanho);
  testBubbleRec(vBubble2, tamanho);

  printf("\n");

  testSelection(vSelect1, tamanho);
  testSelectionRec(vSelect2, tamanho);

  printf("\n");

  testInsertion(vInsert1, tamanho);
  testInsertionRec(vInsert2, tamanho);

  free (vBubble1);
  free (vSelect1);
  free (vInsert1);

  return 0;
}

