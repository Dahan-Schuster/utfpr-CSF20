#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int info;
  struct stack *next;
} Stack;

Stack* create_stack ();

void free_stack (Stack *s);

Stack* push (Stack *s, int elem);

Stack* pop (Stack *s);

int top (Stack *s);

int empty_stack (Stack *s);
