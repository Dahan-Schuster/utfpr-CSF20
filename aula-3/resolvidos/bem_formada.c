#include <string.h>
#include "pilha.h"

int main () {

    char *seq = "( ( ) [ ( ) ] )";
    int tam = 0;

    for (tam; seq[tam] != '\0'; tam++);

    Pilha *abre = create_stack(tam);
    Pilha *fecha = create_stack(tam);

    char c;
    int i = 0,
        qteAbres = 0,
        qteFechas = 0,
        isBemFormada = 1;

    for (i; i < tam; i++) {
        c = seq[i];
      
        if (c == '[' || c == '(') {
            push (abre, c);
        } else if (c == ']' || c == ')') {
            push (fecha, c);
        }
    }

    printf("\n");


    printf("\n");
    if (isBemFormada)
        printf ("Bem Formada!\n");
    else
        printf ("Mal formada!\n");

    destroy_stack (abre);

    return 0;
}

