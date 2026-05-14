#include <stdio.h>
#include "recursao.h"
#include "interface.h"

int main(void) {
    int opcao;
    int n, base, exp;

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                n = lerInteiro("   Digite um numero decimal (>= 0): ");
                if (n < 0) {
                    printf("   Erro: use um numero nao-negativo.\n");
                } else if (n == 0) {
                    printf("\n>>> Resultado de decToBin(0): 0\n");
                } else {
                    printf("\n>>> Resultado de decToBin(%d): ", n);
                    decToBin(n);
                    printf("\n");
                }
                break;

            case 2:
                base = lerInteiro("   Digite a base: ");
                exp  = lerInteiro("   Digite o expoente (>= 0): ");
                if (exp < 0) {
                    printf("   Erro: expoente deve ser >= 0.\n");
                } else {
                    exibirResultado("potencia", (long long)potencia(base, exp));
                }
                break;

            case 3:
                n = lerInteiro("   Digite um numero inteiro: ");
                exibirResultado("somaDigitos", (long long)somaDigitos(n));
                break;

            case 0:
                printf("\n   Encerrando o CUCC. Ate logo!\n\n");
                break;

            default:
                printf("\n   Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
