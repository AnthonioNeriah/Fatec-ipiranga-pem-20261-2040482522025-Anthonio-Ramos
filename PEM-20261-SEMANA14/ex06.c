/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */
#include <stdio.h>

int main(void) {
    long long n;
    int passos = 0;

    printf("=== Conjectura de Collatz ===\n\n");

    /* Controle de entrada: rejeita valores <= 0 */
    do {
        printf("Digite um inteiro positivo: ");
        scanf("%lld", &n);
        if (n <= 0)
            printf("Valor inválido! Digite um número maior que zero.\n");
    } while (n <= 0);

    printf("\nSequência de Collatz para %lld:\n%lld", n, n);

    /* while: continua enquanto n != 1 */
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;          /* par: divide por 2 */
        } else {
            n = 3 * n + 1;      /* ímpar: 3n + 1 */
        }
        printf(" → %lld", n);
        passos++;
    }

    printf("\n\nNúmero de passos: %d\n", passos);
    return 0;
}
