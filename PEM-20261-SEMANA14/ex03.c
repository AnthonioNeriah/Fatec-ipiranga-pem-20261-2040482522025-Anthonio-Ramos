/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

int main(void) {
    double peso, altura, imc;

    printf("=== Classificador de IMC ===\n\n");

    printf("Digite o peso (kg): ");
    scanf("%lf", &peso);

    printf("Digite a altura (m): ");
    scanf("%lf", &altura);

    /* Validação de entrada */
    if (peso <= 0.0 || altura <= 0.0) {
        printf("Erro: peso e altura devem ser valores positivos.\n");
        return 1;
    }

    imc = peso / (altura * altura);

    printf("\nIMC calculado: %.2f\n", imc);

    /* Classificação por if encadeado conforme tabela da OMS */
    if (imc < 18.5) {
        printf("Classificação: Abaixo do peso\n");
    } else if (imc < 25.0) {
        printf("Classificação: Peso normal\n");
    } else if (imc < 30.0) {
        printf("Classificação: Sobrepeso\n");
    } else {
        printf("Classificação: Obesidade\n");
    }

    return 0;
}
