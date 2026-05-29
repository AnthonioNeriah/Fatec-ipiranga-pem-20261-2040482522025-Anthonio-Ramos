/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

#define CM_POR_KM    100000.0
#define KM_POR_MILHA 1.60934

int main(void) {
    int distCm;

    printf("=== Conversor de Unidades ===\n\n");
    printf("Digite a distância em centímetros: ");
    scanf("%d", &distCm);

    /* Validação: rejeita valores não-positivos sem encerrar abruptamente */
    if (distCm <= 0) {
        printf("Erro: a distância deve ser um valor positivo.\n");
        return 1;
    }

    float  metros     = (float)distCm / 100.0f;
    double kilometros = (double)distCm / CM_POR_KM;
    double milhas     = kilometros / KM_POR_MILHA;

    printf("\nDistância em centímetros : %d cm\n",   distCm);
    printf("Distância em metros      : %.2f m\n",   metros);
    printf("Distância em quilômetros : %.6f km\n",  kilometros);
    printf("Distância em milhas      : %.6f mi\n",  milhas);

    return 0;
}
