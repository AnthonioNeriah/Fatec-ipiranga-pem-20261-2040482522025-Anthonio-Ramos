/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */
#include <stdio.h>

int main(void) {
    int num, mult;
    char resp;

    printf("=== Tabuada Interativa ===\n");

    /* do-while: garante que o programa execute ao menos uma vez
     * e só encerra quando o usuário digitar 'N'. */
    do {
        /* for: itera sobre cada número (tabuada) de 1 a 10 */
        for (num = 1; num <= 10; num++) {
            printf("\n--- Tabuada do %d ---\n", num);
            mult = 1;

            /* while: itera sobre o multiplicador de 1 a 10 */
            while (mult <= 10) {
                printf("%2d x %2d = %3d\n", num, mult, num * mult);
                mult++;
            }

            /* Ao final de cada tabuada, pergunta se continua */
            if (num < 10) {
                printf("\nContinuar para a próxima tabuada? (S/N): ");
                scanf(" %c", &resp);
                if (resp == 'N' || resp == 'n') {
                    printf("Encerrando...\n");
                    return 0;
                }
            }
        }

        printf("\nDeseja reiniciar as tabuadas? (S/N): ");
        scanf(" %c", &resp);

    } while (resp == 'S' || resp == 's');

    printf("Programa encerrado.\n");
    return 0;
}
