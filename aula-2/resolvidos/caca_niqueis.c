#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "queue.c"
#include "carretel.c"

#define VALOR_GIRO 1000

/**
 * Verifica se os números sorteados pelos carreteis formam um jackpot,
 * ou seja, são todos iguais
 */
int verificar_jackpot (Carretel *c1, Carretel *c2, Carretel *c3) {
    return (c1->numero_sorteado == c2->numero_sorteado &&
            c2->numero_sorteado == c3->numero_sorteado);
}

/**
 * Calcula o premio do jackpot com base no número sorteado
 * e no valor total acumulado no caça níqueis a cada giro
 */
float calcular_premio (Carretel *c, float valorAcumulado) {
   // o valor do prêmio será uma porcentagem do valor acumulado
   float porcentagem = c->numero_sorteado / 10.0;
    
   // valor máximo: 90%; valor mínimo: 10%
   return valorAcumulado * porcentagem;
}

int main () {
    srand(time(0));

    Carretel *c1 = criar_carretel();
    Carretel *c2 = criar_carretel();
    Carretel *c3 = criar_carretel();

    int ganhou = 0;
    float valorAcumulado = 0;

    while (!ganhou) {
        valorAcumulado += VALOR_GIRO;

        printf("%d", girar_carretel(c1));
        printf("%d", girar_carretel(c2));
        printf("%d\n", girar_carretel(c3));

        ganhou = verificar_jackpot (c1, c2, c3);
        
        sleep(1);
    }
    
    float premio = calcular_premio (c1, valorAcumulado);

    printf("Parabéns, você ganhou!\nPrêmio ganho: R$ %.2f\n", premio);
    
    free_carretel(c1);
    free_carretel(c2);
    free_carretel(c3);

    return 0;
}
