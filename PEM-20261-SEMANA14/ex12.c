/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */
#include <stdio.h>

#define TAM 5

/* Troca os valores de duas variáveis via ponteiros */
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Retorna o menor e o maior elemento de um vetor de tamanho n.
 * Resultados gravados nos ponteiros min e max.
 */
void minMax(int *v, int n, int *min, int *max) {
    int i;
    *min = *max = *v; /* inicializa com o primeiro elemento */
    for (i = 1; i < n; i++) {
        if (*(v + i) < *min) *min = *(v + i);
        if (*(v + i) > *max) *max = *(v + i);
    }
}

/*
 * Normaliza o vetor para o intervalo [0, 1]:
 * divide cada elemento pelo maior valor encontrado.
 */
void normalizaVetor(float *v, int n) {
    int i;
    float maior = *v;
    for (i = 1; i < n; i++)
        if (*(v + i) > maior) maior = *(v + i);

    if (maior == 0.0f) return; /* evita divisão por zero */

    for (i = 0; i < n; i++)
        *(v + i) /= maior;
}

int main(void) {
    /* --- Demonstração de troca() --- */
    int x = 7, y = 42;
    printf("=== troca() ===\n");
    printf("Antes : x=%d, y=%d\n", x, y);
    troca(&x, &y);
    printf("Depois: x=%d, y=%d\n\n", x, y);

    /* --- Demonstração de minMax() --- */
    int v[TAM] = {15, 3, 99, 47, 8};
    int minVal, maxVal;
    int i;

    printf("=== minMax() ===\n");
    printf("Vetor: ");
    for (i = 0; i < TAM; i++) printf("%d ", v[i]);
    printf("\n");

    minMax(v, TAM, &minVal, &maxVal);
    printf("Mínimo: %d | Máximo: %d\n\n", minVal, maxVal);

    /* --- Demonstração de normalizaVetor() --- */
    float fv[TAM] = {10.0f, 25.0f, 5.0f, 50.0f, 40.0f};
    printf("=== normalizaVetor() ===\n");
    printf("Antes : ");
    for (i = 0; i < TAM; i++) printf("%.2f ", fv[i]);
    printf("\n");

    normalizaVetor(fv, TAM);
    printf("Depois: ");
    for (i = 0; i < TAM; i++) printf("%.4f ", fv[i]);
    printf("\n");

    return 0;
}
