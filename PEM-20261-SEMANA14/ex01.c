/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

int main(void) {
    double n1, n2, n3;
    int    p1, p2, p3;

    printf("=== Calculadora de Média Ponderada ===\n\n");

    printf("Digite a nota 1 e seu peso: ");
    scanf("%lf %d", &n1, &p1);

    printf("Digite a nota 2 e seu peso: ");
    scanf("%lf %d", &n2, &p2);

    printf("Digite a nota 3 e seu peso: ");
    scanf("%lf %d", &n3, &p3);

    double media = (n1 * p1 + n2 * p2 + n3 * p3) / (double)(p1 + p2 + p3);

    printf("\nMédia ponderada: %.2f\n", media);

    printf("\n--- Tamanhos dos tipos utilizados ---\n");
    printf("sizeof(double) = %zu bytes\n", sizeof(double));
    printf("sizeof(int)    = %zu bytes\n", sizeof(int));

    return 0;
}
