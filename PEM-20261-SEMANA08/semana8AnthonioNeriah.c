/*
 * ============================================================
 * FATEC IPIRANGA - Programacao Estruturada e Modular (PEM)
 * Docente: Prof. Verissimo
 * Atividade 8 - Semana 08: Gestao de Carga em Logistica
 *               (Ponteiros e Vetores)
 * ============================================================
 * Descricao:
 *   Sistema de validacao de peso para uma transportadora digital.
 *   Recebe um lote de 10 pacotes, aplica calibracao via ponteiros
 *   e exibe o estado do vetor antes e apos o processamento.
 * ============================================================
 */

#include <stdio.h>

#define TAMANHO 10
#define FATOR_EXCESSO 1.10f   /* peso > media * 1.10 e considerado excedente */
#define FATOR_CORRECAO 0.95f  /* correcao de -5% aplicada via ponteiro       */

/* ---------------------------------------------------------
 * processarCarga
 * Parametros:
 *   ptr_vetor - ponteiro para o primeiro elemento do vetor
 *   n         - quantidade de pacotes no lote
 * Funcionalidades:
 *   a) Calcula a media aritmetica dos pesos
 *   b) Localiza pesos que excedam a media em mais de 10%
 *   c) Aplica correcao de -5% diretamente no endereco de
 *      memoria do elemento excedente (via ponteiro)
 * --------------------------------------------------------- */
void processarCarga(float *ptr_vetor, int n) {
    float soma = 0.0f;
    float media;
    float *ptr;   /* ponteiro auxiliar para percorrer o vetor */
    int   i;
    int   corrigidos = 0;

    /* --- (a) Calcula a media usando aritmetica de ponteiros --- */
    for (ptr = ptr_vetor, i = 0; i < n; i++, ptr++) {
        soma += *ptr;
    }
    media = soma / (float)n;

    printf("\n  Media aritmetica do lote: %.2f kg\n", media);
    printf("  Limite para excesso (media + 10%%): %.2f kg\n\n",
           media * FATOR_EXCESSO);

    /* --- (b) e (c) Localiza excedentes e corrige via ponteiro --- */
    for (ptr = ptr_vetor, i = 0; i < n; i++, ptr++) {
        if (*ptr > media * FATOR_EXCESSO) {
            printf("  [AJUSTE] Pacote %2d: %.2f kg  ->  ", i + 1, *ptr);
            *ptr *= FATOR_CORRECAO;   /* correcao de -5% no endereco de memoria */
            printf("%.2f kg  (endereco: %p)\n", *ptr, (void *)ptr);
            corrigidos++;
        }
    }

    if (corrigidos == 0) {
        printf("  Nenhum pacote excedeu o limite. Nenhuma correcao necessaria.\n");
    } else {
        printf("\n  Total de pacotes corrigidos: %d\n", corrigidos);
    }
}

/* ---------------------------------------------------------
 * exibirVetor
 * Exibe o conteudo do vetor usando aritmetica de ponteiros.
 * --------------------------------------------------------- */
void exibirVetor(float *ptr_vetor, int n, const char *titulo) {
    float *ptr;
    int i;

    printf("\n%s\n", titulo);
    printf("  +--------+------------+----------------------+\n");
    printf("  | Pacote |   Peso(kg) |      Endereco        |\n");
    printf("  +--------+------------+----------------------+\n");

    for (ptr = ptr_vetor, i = 0; i < n; i++, ptr++) {
        printf("  |  %5d | %10.2f | %20p |\n",
               i + 1, *ptr, (void *)ptr);
    }

    printf("  +--------+------------+----------------------+\n");
}

/* ---------------------------------------------------------
 * main
 * Declara e inicializa o vetor de pesos (REQ01).
 * Chama as funcoes passando o vetor por referencia.
 * --------------------------------------------------------- */
int main(void) {
    /* REQ01 - vetor declarado e inicializado em main */
    float pesos[TAMANHO] = {
        12.5f, 18.0f, 9.3f,  22.7f, 15.1f,
        30.4f, 11.8f, 25.0f, 8.6f,  19.9f
    };

    printf("=================================================\n");
    printf("   SISTEMA DE GESTAO DE CARGA - TRANSPORTADORA  \n");
    printf("=================================================\n");

    /* REQ04 - exibir estado ANTES do processamento */
    exibirVetor(pesos, TAMANHO, "--- ESTADO DO VETOR ANTES DO PROCESSAMENTO ---");

    /* REQ02 / REQ03 - processar carga via ponteiro */
    printf("\n--- PROCESSAMENTO DE CALIBRACAO ---");
    processarCarga(pesos, TAMANHO);   /* passa o endereco do primeiro elemento */

    /* REQ04 - exibir estado APOS o processamento */
    exibirVetor(pesos, TAMANHO, "--- ESTADO DO VETOR APOS O PROCESSAMENTO ---");

    printf("\n=================================================\n");
    printf("   Processamento concluido. Carga validada.     \n");
    printf("=================================================\n");

    return 0;
}
