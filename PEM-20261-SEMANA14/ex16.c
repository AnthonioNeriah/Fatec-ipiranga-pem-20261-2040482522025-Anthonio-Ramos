/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 12

/* Contadores globais */
int chamadasBusca = 0;
int profBusca     = 0;
int maxProfBusca  = 0;

int chamadasSoma  = 0;
int profSoma      = 0;
int maxProfSoma   = 0;

/*
 * buscaRec(v, n, chave)
 *
 * CASO BASE   : n == 0 → vetor vazio, elemento não encontrado → retorna -1.
 * CASO BASE   : *v == chave → encontrou na posição relativa 0 → retorna o índice.
 * PASSO RECURSIVO: chama a si mesma para o restante do vetor (v+1, n-1);
 *                  se encontrar, ajusta o índice (+1) antes de retornar.
 */
int buscaRec(int *v, int n, int chave) {
    chamadasBusca++;
    profBusca++;
    if (profBusca > maxProfBusca) maxProfBusca = profBusca;

    /* CASO BASE 1: vetor esgotado sem encontrar o elemento */
    if (n == 0) {
        profBusca--;
        return -1;
    }

    /* CASO BASE 2: elemento encontrado na posição atual */
    if (*v == chave) {
        profBusca--;
        return 0;
    }

    /* PASSO RECURSIVO: busca no restante do vetor */
    int idx = buscaRec(v + 1, n - 1, chave);
    profBusca--;

    /* Se encontrado, o índice real é idx + 1 (deslocamento pelo avanço de v) */
    return (idx == -1) ? -1 : idx + 1;
}

/*
 * somaRec(v, ini, fim)
 *
 * CASO BASE   : ini == fim → intervalo de um elemento → retorna v[ini].
 * PASSO RECURSIVO: divide o intervalo ao meio, soma recursivamente cada metade
 *                  e retorna a soma total.
 */
int somaRec(int *v, int ini, int fim) {
    chamadasSoma++;
    profSoma++;
    if (profSoma > maxProfSoma) maxProfSoma = profSoma;

    int resultado;

    /* CASO BASE: intervalo de um único elemento */
    if (ini == fim) {
        resultado = v[ini];
    } else {
        /* PASSO RECURSIVO: divide em duas metades e soma cada uma */
        int meio = (ini + fim) / 2;
        resultado = somaRec(v, ini, meio) + somaRec(v, meio + 1, fim);
    }

    profSoma--;
    return resultado;
}

int main(void) {
    int v[TAM];
    int i, chave, idx;

    srand((unsigned int)time(NULL));

    /* Geração do vetor com valores aleatórios entre 1 e 50 */
    printf("=== Busca Recursiva e Soma por Divisão ===\n\n");
    printf("Vetor gerado: [ ");
    for (i = 0; i < TAM; i++) {
        v[i] = rand() % 50 + 1;
        printf("%d ", v[i]);
    }
    printf("]\n");

    /* Soma total usando somaRec */
    int soma = somaRec(v, 0, TAM - 1);
    printf("\nSoma total (somaRec)      : %d\n", soma);
    printf("  Chamadas recursivas     : %d\n", chamadasSoma);
    printf("  Profundidade máxima     : %d\n", maxProfSoma);

    /* Busca com buscaRec */
    printf("\nDigite um valor para buscar: ");
    scanf("%d", &chave);

    idx = buscaRec(v, TAM, chave);

    printf("\nResultado da busca (buscaRec):\n");
    if (idx >= 0)
        printf("  Valor %d encontrado no índice %d.\n", chave, idx);
    else
        printf("  Valor %d não encontrado no vetor.\n", chave);

    printf("  Chamadas recursivas     : %d\n", chamadasBusca);
    printf("  Profundidade máxima     : %d\n", maxProfBusca);

    return 0;
}
