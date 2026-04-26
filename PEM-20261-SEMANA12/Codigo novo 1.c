/*
 *Nome: Anthonio Neriah Pereira Ramos
 * FATEC IPIRANGA - Centro Paula Souza
 * Disciplina: PEM - Programação Estruturada e Modular
 * Docente: Prof. Veríssimo
 * Atividade: Semana 12 - Código Novo 1
 *
 * SOLUÇÃO DO BENCHMARK:
 *   A operação é executada N_REP (100.000) vezes dentro de um loop.
 *   O tempo total medido pelo clock() é então dividido pelo número
 *   de repetições, obtendo o tempo médio real por execução.
 *   Técnica padrão para medir operações rápidas com clock().
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS    50
#define LIMITE_ALERTA 300.0
#define N_REP         100000

typedef struct {
    char  nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int   subpastas_indices[10];
    int   qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];
unsigned long long ciclos_por_exec = 0;

void initPasta(Pasta *p, const char *nome, float tam) {
    strncpy(p->nome, nome, sizeof(p->nome) - 1);
    p->tamanho_proprio = tam;
    p->tamanho_total   = 0.0f;
    p->qtd_sub         = 0;
}

void addSubpasta(Pasta *pai, int idx_filho) {
    if (pai->qtd_sub < 10)
        pai->subpastas_indices[pai->qtd_sub++] = idx_filho;
}

void resetTamanhos(void) {
    for (int i = 0; i < MAX_PASTAS; i++)
        drive[i].tamanho_total = drive[i].tamanho_proprio;
}

/* Processamento recursivo — parâmetros via ponteiro */
float processarHierarquia(const int *index,
                           const int *nivel_atual,
                           const int *limite_profund,
                           unsigned long long *ciclos)
{
    (*ciclos)++;
    if (*index == -1 || *nivel_atual > *limite_profund) return 0.0f;

    Pasta *p = &drive[*index];
    p->tamanho_total = p->tamanho_proprio;

    for (int i = 0; i < p->qtd_sub; i++) {
        int filho_idx  = p->subpastas_indices[i];
        int prox_nivel = *nivel_atual + 1;
        p->tamanho_total += processarHierarquia(&filho_idx, &prox_nivel,
                                                limite_profund, ciclos);
    }
    return p->tamanho_total;
}

/* Exibição separada do benchmark (roda só 1x após medir) */
void exibir(const int *idx, const int *nivel, const int *lim) {
    if (*idx == -1 || *nivel > *lim) return;
    Pasta *p = &drive[*idx];
    for (int i = 0; i < *nivel; i++) printf("  ");
    printf("|-- %s [%.2f GB]", p->nome, p->tamanho_total);
    if (p->tamanho_total > LIMITE_ALERTA) printf(" [!] ALERTA: GARGALO DETECTADO");
    printf("\n");
    for (int i = 0; i < p->qtd_sub; i++) {
        int f = p->subpastas_indices[i], prox = *nivel + 1;
        exibir(&f, &prox, lim);
    }
}

int main(void) {
    initPasta(&drive[0], "RAIZ",            10.0f); addSubpasta(&drive[0], 1); addSubpasta(&drive[0], 2);
    initPasta(&drive[1], "Projetos_TI",     50.0f); addSubpasta(&drive[1], 3);
    initPasta(&drive[2], "Backups_Antigos", 350.0f);
    initPasta(&drive[3], "Videos_Aulas",    280.0f);

    int limite, raiz = 0, nivel_ini = 0;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    /* ── Benchmark: N_REP repetições ── */
    clock_t t = clock();
    for (int r = 0; r < N_REP; r++) {
        resetTamanhos();
        unsigned long long c_temp = 0;
        processarHierarquia(&raiz, &nivel_ini, &limite, &c_temp);
        if (r == 0) ciclos_por_exec = c_temp;
    }
    t = clock() - t;

    double tempo_total = ((double)t) / CLOCKS_PER_SEC;
    double tempo_medio = tempo_total / N_REP;

    /* Roda 1x para exibir resultado correto */
    resetTamanhos();
    unsigned long long c_dummy = 0;
    processarHierarquia(&raiz, &nivel_ini, &limite, &c_dummy);

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE (Codigo Novo 1 - Ponteiros) ---\n");
    exibir(&raiz, &nivel_ini, &limite);
    printf("------------------------------------------------------------------------\n");
    printf("Ciclos por execucao               : %llu\n",   ciclos_por_exec);
    printf("Repeticoes para benchmark         : %d\n",     N_REP);
    printf("Tempo total (%6d repeticoes)  : %.6f s\n",    N_REP, tempo_total);
    printf("Tempo medio por execucao          : %.9f s\n", tempo_medio);
    printf("------------------------------------------------------------------------\n");

    return 0;
}
