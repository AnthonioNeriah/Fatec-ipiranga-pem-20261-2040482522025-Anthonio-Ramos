/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */


#include <stdio.h>

int main(void) {
    double a, b, c;

    printf("=== Validador e Classificador de Triângulo ===\n\n");
    printf("Digite os três lados do triângulo: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    /* --- Passo 1: Verificação da desigualdade triangular ---
     * Um triângulo é válido somente se a soma de dois lados
     * quaisquer é estritamente maior que o terceiro lado. */
    if ((a + b > c) && (a + c > b) && (b + c > a)) {

        printf("\nOs valores formam um triângulo válido.\n");

        /* --- Passo 2: Classificação pelos lados ---
         * Equilátero: todos os lados iguais.
         * Isósceles : exatamente dois lados iguais.
         * Escaleno  : todos os lados diferentes. */
        if (a == b && b == c) {
            printf("Tipo (lados)  : Equilátero\n");
        } else if (a == b || a == c || b == c) {
            printf("Tipo (lados)  : Isósceles\n");
        } else {
            printf("Tipo (lados)  : Escaleno\n");
        }

        /* --- Passo 3: Classificação pelos ângulos ---
         * Identificamos o maior lado (hipotenusa candidata)
         * e comparamos o quadrado dele com a soma dos quadrados
         * dos outros dois, usando a relação de Pitágoras generalizada.
         *
         * c² == a² + b² → Retângulo
         * c² >  a² + b² → Obtusângulo (ângulo maior que 90°)
         * c² <  a² + b² → Acutângulo  (todos os ângulos menores que 90°)
         *
         * Determinamos o maior lado para ser a "hipotenusa" candidata. */
        double maior, x, y;

        if (a >= b && a >= c) {
            maior = a; x = b; y = c;
        } else if (b >= a && b >= c) {
            maior = b; x = a; y = c;
        } else {
            maior = c; x = a; y = b;
        }

        double quadMaior = maior * maior;
        double somaQuad  = x * x + y * y;

        if (quadMaior == somaQuad) {
            printf("Tipo (ângulos): Retângulo\n");
        } else if (quadMaior > somaQuad) {
            printf("Tipo (ângulos): Obtusângulo\n");
        } else {
            printf("Tipo (ângulos): Acutângulo\n");
        }

    } else {
        /* Desigualdade triangular não satisfeita */
        printf("\nOs valores NÃO formam um triângulo válido.\n");
    }

    return 0;
}
