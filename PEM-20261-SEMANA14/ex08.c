/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

#define N 8

int main(void) {
    int v[N], inv[N];
    int i;

    printf("=== Análise e Manipulação de Vetores (N=%d) ===\n\n", N);

    /* Leitura */
    for (i = 0; i < N; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    /* Exibição do vetor original */
    printf("\nVetor original: [ ");
    for (i = 0; i < N; i++) printf("%d ", v[i]);
    printf("]\n");

    /* Maior e menor com índices */
    int idxMaior = 0, idxMenor = 0;
    for (i = 1; i < N; i++) {
        if (v[i] > v[idxMaior]) idxMaior = i;
        if (v[i] < v[idxMenor]) idxMenor = i;
    }
    printf("Maior valor: %d (índice %d)\n", v[idxMaior], idxMaior);
    printf("Menor valor: %d (índice %d)\n", v[idxMenor], idxMenor);

    /* Contagem de pares e ímpares */
    int pares = 0, impares = 0;
    for (i = 0; i < N; i++) {
        if (v[i] % 2 == 0) pares++;
        else                impares++;
    }
    printf("Pares: %d | Ímpares: %d\n", pares, impares);

    /* Vetor invertido */
    for (i = 0; i < N; i++) inv[i] = v[N - 1 - i];

    printf("Vetor invertido: [ ");
    for (i = 0; i < N; i++) printf("%d ", inv[i]);
    printf("]\n");

    /* Busca linear */
    int chave, encontrado = -1;
    printf("\nDigite um valor para buscar: ");
    scanf("%d", &chave);

    for (i = 0; i < N; i++) {
        if (v[i] == chave) {
            encontrado = i;
            break;
        }
    }

    if (encontrado >= 0)
        printf("Valor %d encontrado no índice %d.\n", chave, encontrado);
    else
        printf("Valor %d não encontrado no vetor.\n", chave);

    return 0;
}
