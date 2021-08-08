#include <stdlib.h>
#include <time.h>
#include "pilha.h"

#define TAM 9

#define PLAYER_1  1
#define PLAYER_2  2
#define NINGUEM   0
#define AMBOS    -1

/**
 * Preenche a pilha com números aleatórios entre
 * 0 e o tamanho inicial, inclusive
 */
void preencherPilha(Pilha *p) {
   int i;
   for (i = 0; i < TAM; i++) {
      push (p, rand () % TAM);
   }
}

/**
 * Passa uma certa quantidade de elementos da
 * pilha de origem para a pilha de destino
 */
void passarElementos(Pilha *origem, Pilha *destino, int qte) {
   int i;
   for (i = 0; i < qte; i++) {
      if (empty_stack(origem) || full_stack(destino))
         break;
      
      push (destino, pop (origem));
   }
}

/** Verifica o vencendor do jogo, podendo ser PLAYER_1, PLAYER_2 ou NINGUEM */
int verificarVencedor (Pilha *p1, Pilha *p2) {
   if (empty_stack(p1) && empty_stack(p2))
      return AMBOS;
   else if (empty_stack(p1))
      return PLAYER_1;
   else if (empty_stack(p2))
      return PLAYER_2;
   else
      return NINGUEM;   
}

/** Imprime uma mensagem informando o vencedor do jogo */
void anunciarVencedor(int vencedor) {
   if (vencedor == PLAYER_1)
      printf("Player 1 venceu!");
   else if (vencedor == PLAYER_2)
      printf("Player 2 venceu!");
   else
      printf("Ambos venceram! (isso não era pra acontecer)");

  printf("\n");
}

/** Imprime e retorna o número do topo da pilha */
int pegarNumeroDoTopo(Pilha *p) {
   print_stack(p);
   int n = pop (p);
   printf(" --> %d\n", n);
   return n;
}

int main () {

   // gera uma semente de aleatoriadade baseada no timestamp atual
   srand( time (0));

   // cria as duas pilhas com o dobro do número inicial de cartas
   // isto é necessário porque há a possibilidade de todas as cartas
   // de um jogador serem passadas para o outro
   Pilha *p1 = create_stack(TAM * 2);
   Pilha *p2 = create_stack(TAM * 2);

   // inicaliza a variável que indica o vencedor
   int vencendor = NINGUEM;

   // preenche ambas as pilhas com números aleatórios
   preencherPilha(p1);
   preencherPilha(p2);

   // variáveis que guarda o número do topo de cada pilha em cada rodada
   int n1, n2;

   // enquanto ninguém venceu, inicia uma nova rodada
   while (vencendor == NINGUEM) {
      
      // pega e descarta os números do topo de cada pilha
      n1 = pegarNumeroDoTopo(p1);
      n2 = pegarNumeroDoTopo(p2);
      printf("\n");

      // o número maior vence a rodada, passando a diferença
      // entre ele e o número menor para a outra pilha
      if (n1 > n2) {
         passarElementos(p1, p2, n1 - n2);
      } else if (n2 > n1) {
         passarElementos(p2, p1, n2 - n1);
      }

      // ao final de cada rodada verifica o vencedor
      vencendor = verificarVencedor(p1, p2);
   }

   // ao final do jogo, anuncia o vencedor...
   anunciarVencedor(vencendor);   

   // e desaloca o espaço de memória usado pelas pilhas
   destroy_stack(p1);
   destroy_stack(p2);

   return 0;
}
