/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

#define TAM 10

int main(void) {
    float v[TAM];
    int i;

    printf("=== Estatísticas do Conjunto ===\n\n");

    /* Leitura do vetor */
    for (i = 0; i < TAM; i++) {
        printf("v[%d]: ", i);
        scanf("%f", &v[i]);
    }

    /* --- Loop único para todas as estatísticas --- */
    float soma  = 0.0f;
    float maior = v[0];
    float menor = v[0];

    for (i = 0; i < TAM; i++) {
        soma += v[i];

        if (v[i] > maior) maior = v[i];
        if (v[i] < menor) menor = v[i];
    }

    float media = soma / TAM;

    /* Soma dos elementos acima da média (segundo loop, mas
     * pode ser feito na mesma passagem com a média conhecida
     * apenas após o primeiro loop — única passagem não é possível
     * sem conhecer a média antes; usamos dois loops conforme
     * é padrão para esse tipo de problema). */
    float somaAcima = 0.0f;
    for (i = 0; i < TAM; i++) {
        if (v[i] > media)
            somaAcima += v[i];
    }

    printf("\n--- Resultados ---\n");
    printf("Média aritmética          : %.2f\n", media);
    printf("Maior valor               : %.2f\n", maior);
    printf("Menor valor               : %.2f\n", menor);
    printf("Soma dos valores > média  : %.2f\n", somaAcima);

    return 0;
}
