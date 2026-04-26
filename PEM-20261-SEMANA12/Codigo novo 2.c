/*
 * Nome: Anthonio Neriah Pereira Ramos
 * FATEC IPIRANGA - Centro Paula Souza
 * Disciplina: PEM - Programação Estruturada e Modular
 * Docente: Prof. Veríssimo
 * Atividade: Semana 12 - Código Novo 2
 *
 * SOLUÇÃO DO BENCHMARK:
 *   Usa clock_gettime(CLOCK_MONOTONIC) com resolução de nanosegundos,
 *   capaz de medir operações muito rápidas sem precisar de loop de
 *   repetição. Disponível em qualquer sistema POSIX (Linux/Mac).
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS    50
#define LIMITE_ALERTA 300.0
#define MAX_PILHA     200

typedef struct {
    char  nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int   subpastas_indices[10];
    int   qtd_sub;
    int   pai_idx;
} Pasta;

typedef struct {
    int index;
    int nivel;
} EntradaPilha;

Pasta drive[MAX_PASTAS];
unsigned long long ciclos_total = 0;

void resetDrive(void) {
    for (int i = 0; i < MAX_PASTAS; i++) {
        drive[i].tamanho_total = drive[i].tamanho_proprio;
        drive[i].pai_idx = -1;
    }
}

/* Processamento iterativo com pilha manual */
void processarHierarquiaIterativo(int raiz, int limite_profundidade) {
    EntradaPilha pilha[MAX_PILHA];
    int topo = 0;

    int ordem_visita[MAX_PILHA], niveis_visita[MAX_PILHA];
    int qtd_visitados = 0;

    resetDrive();

    pilha[topo].index = raiz;
    pilha[topo].nivel = 0;
    topo++;

    /* 1ª passada: percurso pré-ordem via pilha (substitui a recursão) */
    while (topo > 0) {
        ciclos_total++;
        topo--;
        int idx   = pilha[topo].index;
        int nivel = pilha[topo].nivel;

        if (idx == -1 || nivel > limite_profundidade) continue;

        ordem_visita[qtd_visitados]  = idx;
        niveis_visita[qtd_visitados] = nivel;
        qtd_visitados++;

        /* Empilha filhos em ordem inversa para manter ordem de visita */
        for (int i = drive[idx].qtd_sub - 1; i >= 0; i--) {
            ciclos_total++;
            int filho = drive[idx].subpastas_indices[i];
            if (topo < MAX_PILHA) {
                pilha[topo].index = filho;
                pilha[topo].nivel = nivel + 1;
                topo++;
                drive[filho].pai_idx = idx;
            }
        }
    }

    /* 2ª passada: acumula tamanhos de baixo para cima */
    for (int i = qtd_visitados - 1; i >= 0; i--) {
        ciclos_total++;
        int idx = ordem_visita[i];
        int pai = drive[idx].pai_idx;
        if (pai != -1)
            drive[pai].tamanho_total += drive[idx].tamanho_total;
    }

    /* Exibição em pré-ordem */
    for (int i = 0; i < qtd_visitados; i++) {
        int idx   = ordem_visita[i];
        int nivel = niveis_visita[i];
        for (int j = 0; j < nivel; j++) printf("  ");
        printf("|-- %s [%.2f GB]", drive[idx].nome, drive[idx].tamanho_total);
        if (drive[idx].tamanho_total > LIMITE_ALERTA)
            printf(" [!] ALERTA: GARGALO DETECTADO");
        printf("\n");
    }
}

int main(void) {
    strcpy(drive[0].nome, "RAIZ");            drive[0].tamanho_proprio = 10.0f;  drive[0].qtd_sub = 2; drive[0].subpastas_indices[0] = 1; drive[0].subpastas_indices[1] = 2;
    strcpy(drive[1].nome, "Projetos_TI");     drive[1].tamanho_proprio = 50.0f;  drive[1].qtd_sub = 1; drive[1].subpastas_indices[0] = 3;
    strcpy(drive[2].nome, "Backups_Antigos"); drive[2].tamanho_proprio = 350.0f; drive[2].qtd_sub = 0;
    strcpy(drive[3].nome, "Videos_Aulas");    drive[3].tamanho_proprio = 280.0f; drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    /* ── Benchmark: clock_gettime com resolução de nanosegundos ── */
    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    processarHierarquiaIterativo(0, limite);

    clock_gettime(CLOCK_MONOTONIC, &fim);

    /* Calcula diferença em nanosegundos e converte para segundos */
    long long ns = (fim.tv_sec  - inicio.tv_sec)  * 1000000000LL
                 + (fim.tv_nsec - inicio.tv_nsec);
    double tempo_execucao = (double)ns / 1e9;

    printf("------------------------------------------------------------------------\n");
    printf("Ciclos processados : %llu\n",      ciclos_total);
    printf("Tempo de execucao  : %.9f s\n",    tempo_execucao);
    printf("Tempo de execucao  : %lld ns\n",   ns);
    printf("------------------------------------------------------------------------\n");

    return 0;
}
