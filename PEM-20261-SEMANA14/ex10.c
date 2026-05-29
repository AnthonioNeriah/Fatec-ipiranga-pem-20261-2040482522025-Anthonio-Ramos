/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

#define TAM 4

/* Exibe o tabuleiro como grade formatada */
void exibeTabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("  +----+----+----+----+\n");
    for (i = 0; i < TAM; i++) {
        printf("  |");
        for (j = 0; j < TAM; j++)
            printf(" %2d |", tab[i][j]);
        printf("\n  +----+----+----+----+\n");
    }
}

/*
 * Verifica se, para cada valor v, suas duas ocorrências
 * são simétricas em relação à diagonal principal.
 * Dois elementos (r1,c1) e (r2,c2) são simétricos em relação
 * à diagonal principal se r1==c2 e r2==c1.
 */
void verificaSimetria(int tab[TAM][TAM]) {
    int i, j, k, l;
    int simetrico = 1; /* assume verdadeiro até encontrar falha */

    for (i = 0; i < TAM && simetrico; i++) {
        for (j = 0; j < TAM && simetrico; j++) {
            /* Para cada posição (i,j), procura a segunda ocorrência do valor */
            int val = tab[i][j];
            int achou = 0;
            for (k = 0; k < TAM && !achou; k++) {
                for (l = 0; l < TAM && !achou; l++) {
                    if ((k != i || l != j) && tab[k][l] == val) {
                        /* Testa simetria: (i,j) e (k,l) simétricos se k==j e l==i */
                        if (k != j || l != i) {
                            simetrico = 0;
                        }
                        achou = 1;
                    }
                }
            }
        }
    }

    if (simetrico)
        printf("Todos os pares são simétricos em relação à diagonal principal.\n");
    else
        printf("Há pares NÃO simétricos em relação à diagonal principal.\n");
}

/* Calcula e exibe as diagonais principal e secundária */
void diagonais(int tab[TAM][TAM]) {
    int i;
    printf("\nDiagonal principal : ");
    for (i = 0; i < TAM; i++)
        printf("%d ", tab[i][i]);

    printf("\nDiagonal secundária: ");
    for (i = 0; i < TAM; i++)
        printf("%d ", tab[i][TAM - 1 - i]);

    printf("\n");
}

int main(void) {
    /*
     * Tabuleiro hardcoded: cada símbolo (1-8) aparece exatamente duas vezes.
     * Os pares (1,2,3,4) são posicionados simetricamente em relação à
     * diagonal principal para ilustrar a verificação.
     *   (0,1)↔(1,0): valor 2   (0,2)↔(2,0): valor 3
     *   (1,3)↔(3,1): valor 6   (2,3)↔(3,2): valor 7
     */
    int tab[TAM][TAM] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 7},  /* (2,3) e (1,3) → 7 não simétrico; mostra caso misto */
        {4, 5, 8, 1}
    };

    printf("=== Jogo da Memória — Análise de Tabuleiro ===\n\n");
    printf("Tabuleiro:\n");
    exibeTabuleiro(tab);

    printf("\nVerificação de simetria:\n");
    verificaSimetria(tab);

    diagonais(tab);

    return 0;
}
