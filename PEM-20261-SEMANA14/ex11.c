/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

#define TAM 6

int main(void) {
    int v[TAM] = {10, 20, 30, 40, 50, 60};
    int *p = v; /* p aponta para o primeiro elemento */
    int i;

    printf("=== Aritmética de Ponteiros ===\n\n");

    /* --- Impressão de cada elemento e seu endereço --- */
    printf("Elementos e endereços:\n");
    for (i = 0; i < TAM; i++) {
        printf("  *(p+%d) = %d  |  endereço: %p\n", i, *(p + i), (void *)(p + i));
    }

    /* --- Verificação da diferença entre endereços consecutivos --- */
    printf("\nDiferença entre endereços consecutivos:\n");
    for (i = 0; i < TAM - 1; i++) {
        /* Subtração de ponteiros retorna número de elementos, não bytes */
        long diff = (long)(p + i + 1) - (long)(p + i);
        printf("  (p+%d) → (p+%d): %ld bytes | sizeof(int) = %zu bytes\n",
               i, i + 1, diff, sizeof(int));
    }

    /* --- Soma dos elementos via aritmética de ponteiros --- */
    int soma = 0;
    for (i = 0; i < TAM; i++)
        soma += *(p + i);
    printf("\nSoma dos elementos: %d\n", soma);

    /* --- Dobrar cada elemento in-place via desreferenciação --- */
    printf("\nDobrando cada elemento in-place...\n");
    for (i = 0; i < TAM; i++)
        *(p + i) *= 2;

    printf("Vetor após dobrar: ");
    for (i = 0; i < TAM; i++)
        printf("%d ", *(p + i));
    printf("\n");

    return 0;
}
