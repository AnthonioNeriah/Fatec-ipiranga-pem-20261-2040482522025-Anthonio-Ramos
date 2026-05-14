#include "recursao.h"
#include <stdio.h>

// Converte decimal para binário exibindo via pilha recursiva
void decToBin(int n) {
    if (n == 0) return;
    decToBin(n / 2);
    printf("%d", n % 2);
}

// Calcula base^exp recursivamente (exp >= 0)
int potencia(int base, int exp) {
    if (exp == 0) return 1;
    return base * potencia(base, exp - 1);
}

// Soma todos os algarismos de n
int somaDigitos(int n) {
    if (n < 0) n = -n;      // suporte a negativos
    if (n == 0) return 0;
    return (n % 10) + somaDigitos(n / 10);
}
