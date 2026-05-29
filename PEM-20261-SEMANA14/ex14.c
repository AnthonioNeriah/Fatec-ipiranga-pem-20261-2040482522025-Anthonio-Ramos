/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */

#include <stdio.h>

/* --------------------------------------------------------
 * mdc(a, b)
 * Parâmetros : dois inteiros positivos a e b
 * Retorno    : maior divisor comum pelo algoritmo de Euclides
 * Complexidade: O(log(min(a,b)))
 * -------------------------------------------------------- */
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* --------------------------------------------------------
 * potencia(base, exp)
 * Parâmetros : base (int), exp (int não-negativo)
 * Retorno    : base^exp calculado por multiplicações sucessivas
 * Complexidade: O(exp)
 * -------------------------------------------------------- */
long long potencia(int base, int exp) {
    long long result = 1;
    int i;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

/* --------------------------------------------------------
 * ePrimo(n)
 * Parâmetros : inteiro n >= 2
 * Retorno    : 1 se n é primo, 0 caso contrário
 * Complexidade: O(sqrt(n)) — verifica divisores até √n
 * -------------------------------------------------------- */
int ePrimo(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; (long long)i * i <= (long long)n; i++)
        if (n % i == 0) return 0;
    return 1;
}

/* --------------------------------------------------------
 * decParaBinario(n, buf)
 * Parâmetros : n (inteiro não-negativo), buf (char* para resultado)
 * Retorno    : void; grava string binária em buf
 * Complexidade: O(log2(n))
 * -------------------------------------------------------- */
void decParaBinario(int n, char *buf) {
    if (n == 0) {
        buf[0] = '0'; buf[1] = '\0';
        return;
    }
    int bits[32], count = 0, i;
    while (n > 0) {
        bits[count++] = n % 2;
        n /= 2;
    }
    for (i = 0; i < count; i++)
        buf[i] = '0' + bits[count - 1 - i];
    buf[count] = '\0';
}

int main(void) {
    int opcao;
    char binStr[33];

    printf("=== Calculadora Modular ===\n");

    do {
        printf("\n1. MDC (Algoritmo de Euclides)\n");
        printf("2. Potência inteira\n");
        printf("3. Verificar se é primo\n");
        printf("4. Decimal → Binário\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int a, b;
            printf("Digite dois inteiros positivos: ");
            scanf("%d %d", &a, &b);
            printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));

        } else if (opcao == 2) {
            int base, exp;
            printf("Base e expoente (não-negativo): ");
            scanf("%d %d", &base, &exp);
            printf("%d^%d = %lld\n", base, exp, potencia(base, exp));

        } else if (opcao == 3) {
            int n;
            printf("Digite um número: ");
            scanf("%d", &n);
            printf("%d %s primo.\n", n, ePrimo(n) ? "É" : "NÃO é");

        } else if (opcao == 4) {
            int n;
            printf("Digite um inteiro não-negativo: ");
            scanf("%d", &n);
            decParaBinario(n, binStr);
            printf("%d em binário = %s\n", n, binStr);

        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    printf("Encerrando calculadora.\n");
    return 0;
}
