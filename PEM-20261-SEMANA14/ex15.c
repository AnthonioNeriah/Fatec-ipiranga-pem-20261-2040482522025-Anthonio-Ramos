/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

int totalMovimentos = 0; /* contador global de movimentos */

/*
 * hanoi(n, origem, destino, auxiliar)
 *
 * CASO BASE   : n == 1 → move diretamente o único disco de origem para destino.
 * PASSO RECURSIVO:
 *   1. Move os (n-1) discos de cima da origem para o auxiliar (usando destino).
 *   2. Move o disco n (maior) da origem para o destino.
 *   3. Move os (n-1) discos do auxiliar para o destino (usando origem).
 */
void hanoi(int n, char origem, char destino, char auxiliar) {
    /* CASO BASE: só há um disco — basta movê-lo diretamente */
    if (n == 1) {
        printf("  Mova disco 1 de [%c] para [%c]\n", origem, destino);
        totalMovimentos++;
        return;
    }

    /* PASSO RECURSIVO — parte 1:
     * Libera o pino de destino movendo (n-1) discos para o auxiliar */
    hanoi(n - 1, origem, auxiliar, destino);

    /* Move o disco n (o maior do grupo atual) */
    printf("  Mova disco %d de [%c] para [%c]\n", n, origem, destino);
    totalMovimentos++;

    /* PASSO RECURSIVO — parte 2:
     * Coloca os (n-1) discos do auxiliar sobre o destino */
    hanoi(n - 1, auxiliar, destino, origem);
}

/* Calcula 2^n como inteiro (para N ≤ 10, cabe em int) */
int potencia2(int n) {
    int r = 1, i;
    for (i = 0; i < n; i++) r *= 2;
    return r;
}

int main(void) {
    int N;

    printf("=== Torre de Hanói ===\n\n");

    do {
        printf("Digite o número de discos (1 a 10): ");
        scanf("%d", &N);
        if (N < 1 || N > 10)
            printf("Valor inválido. Use entre 1 e 10.\n");
    } while (N < 1 || N > 10);

    printf("\nMovimentos:\n");
    hanoi(N, 'A', 'C', 'B');

    int esperado = potencia2(N) - 1;
    printf("\nTotal de movimentos realizados : %d\n", totalMovimentos);
    printf("Fórmula 2^%d - 1              : %d\n", N, esperado);
    printf("Confere? %s\n", (totalMovimentos == esperado) ? "Sim!" : "Não.");

    return 0;
}
