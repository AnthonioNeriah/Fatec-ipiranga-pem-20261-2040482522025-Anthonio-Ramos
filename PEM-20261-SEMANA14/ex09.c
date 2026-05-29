/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */
#include <stdio.h>

#define LIN 3
#define COL 3

/* Função auxiliar para exibir uma matriz formatada */
void exibeMatriz(int m[LIN][COL], char nome) {
    int i, j;
    printf("Matriz %c:\n", nome);
    for (i = 0; i < LIN; i++) {
        printf("  [ ");
        for (j = 0; j < COL; j++)
            printf("%4d ", m[i][j]);
        printf("]\n");
    }
}

int main(void) {
    int A[LIN][COL], B[LIN][COL], C[LIN][COL];
    int i, j, k;

    printf("=== Multiplicação de Matrizes 3×3 ===\n\n");

    /* Leitura de A */
    printf("Digite os elementos da Matriz A (%dx%d):\n", LIN, COL);
    for (i = 0; i < LIN; i++)
        for (j = 0; j < COL; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }

    /* Leitura de B */
    printf("\nDigite os elementos da Matriz B (%dx%d):\n", LIN, COL);
    for (i = 0; i < LIN; i++)
        for (j = 0; j < COL; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }

    /* Produto matricial C = A × B
     * i → linha de A e de C
     * j → coluna de B e de C
     * k → índice interno que percorre a coluna de A e a linha de B
     * C[i][j] acumula o produto ponto a ponto da linha i de A
     * com a coluna j de B. */
    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            C[i][j] = 0;
            for (k = 0; k < COL; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\n");
    exibeMatriz(A, 'A');
    printf("\n");
    exibeMatriz(B, 'B');
    printf("\n");
    exibeMatriz(C, 'C');

    return 0;
}
