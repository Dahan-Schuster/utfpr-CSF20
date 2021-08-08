#include <limits.h>
#include <string.h>
#include "lista.h"

int conta_nos_itr (Lista* l) {
   int i = 0;
   for (l; l != NULL; l = l->next, i++);
   return i;
}

int conta_nos_rec (Lista* lista) {
   // se o nó for nulo, seu tamanho é zero
   if (lista == NULL) {
      return 0;
   }

   // cada nó terá tamanho 1
   // o somatório dos nós é o tamanho da lista
   return 1 + conta_nos_rec(lista->next);
}

int procura_itr (Lista* lista, int elemento) {
   Lista* l;
   int i = 0;

   // incrementa o valor de i até chegar ao fim da fila ou achar o elemento
   for (l = lista; l != NULL; l = l->next) {
      // se o elemento for encontrado, interrompe o loop
      if (l->info == elemento)
         break;

      i++;
   }

   // se l possui valor nulo, então chegou ao fim da fila sem
   // encontrar o elemento e retorna -1
   return l == NULL ? -1 : i;
}

int procura_rec (Lista* lista, int elemento) {
   // verifica se o nó é nulo antes de acessar seus dados
   if (lista == NULL) {
      // se chegou ao último nó, o elemento não existe na lista
      return -1;
   } else if (lista->info == elemento) {
      // se encontrou o elemento, retorna 0 no somatório recursivo
      return 0;
   }

   int resultadoProximo = procura_rec(lista->next, elemento);

   return resultadoProximo < 0
      ? resultadoProximo
      : 1 + resultadoProximo;
}

int lista_max_itr (Lista* lista) {
   Lista* l;
   int maior = INT_MIN;

   // verifica se o valor de cada nó é maior que o máximo registrado
   for (l = lista; l != NULL; l = l->next) {
      if (l->info > maior) {
         maior = l->info;
      }
   }

   return maior;
}

/* A verificação do maior número começa quando chega-se ao final da lista */
int lista_max_rec (Lista* lista) {
   // se chegou ao final, retorna o menor valor possível
   if (lista == NULL) return INT_MIN;

   // verifica o maior valor dentro da sublista formada pelos elementos à
   // direita do nó atual
   int maior = lista_max_rec(lista->next);

   // se o valor do nó atual for maior que o da sublista à direita,
   // salva seu valor como maior
   if (lista->info >= maior) maior = lista->info;
   return maior;
}

int lista_soma_itr (Lista* lista) {
   Lista* l;
   int soma = 0;

   // incrementa o valor somatório até achar o último elemento
   for (l = lista; l != NULL; l = l->next) {
      soma += l->info;
   }

   return soma;
}

int lista_soma_rec (Lista* lista) {
   // se o nó for nulo, seu valor no somatório é zero
   if (lista == NULL) {
      return 0;
   }

   // retorna o valor do nó atual somado ao do próximo
   return lista->info + lista_soma_rec(lista->next);
}

void imprimir_invertida_itr (Lista* lista) {
   Lista *l;

   // irá armazenar os dados da lista em um array auxiliar
   // para isso, busca o tamanho da lista
   int i, sizeLista = conta_nos_itr(lista);
   int aux[sizeLista];
   
   // copia todos os dados da lista para o array auxiliar
   for (i = 0, l = lista; l != NULL; l = l->next, i++) {
      aux[i] = l->info;
   }

   // itera pelo array auxiliar de forma invertida enquanto imprime seus valores
   for (i = sizeLista - 1; i >= 0; i--) {
      printf("%d ", aux[i]);
   }
}

void imprimir_invertida_rec (Lista* lista) {
   if (lista != NULL) {
      // imprime sempre o próximo nó antes do atual
      imprimir_invertida_rec(lista->next);
      printf("%d ", lista->info);
   }
}

/*Função para criar uma lista encadeada vazia!*/
Lista* criar_lista (void) {
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista* inserir (Lista *lista, int elem) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista (Lista *lista) {
   Lista *v; /*var. para percorrer a lista*/
   for (v = lista; v != NULL; v = v->next) {
      printf("%d ", v->info);
   }
   printf("\n");
}

/*Função para desalocar uma lista encadeda!*/
void destruir_lista (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}

