#include "interface.h"
#include <stdio.h>

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int exibirMenu(void) {
    int opcao;
    printf("\n========================================\n");
    printf("   CUCC - Conversor e Calculadora      \n");
    printf("         Cientifica                    \n");
    printf("========================================\n");
    printf(" [1] Decimal -> Binario  (decToBin)   \n");
    printf(" [2] Potencia            (potencia)    \n");
    printf(" [3] Soma de Digitos     (somaDigitos) \n");
    printf(" [0] Sair                              \n");
    printf("========================================\n");
    printf(" Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int lerInteiro(const char *mensagem) {
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    limparBuffer();
    return valor;
}

void exibirResultado(const char *operacao, long long resultado) {
    printf("\n>>> Resultado de %s: %lld\n", operacao, resultado);
}
