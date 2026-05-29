/*
 * stringutil.c — Implementação da biblioteca de strings
 * Compilar junto com main.c: gcc main.c stringutil.c -o prog
 */

#include <string.h>   /* strlen — única função de string.h permitida */
#include "stringutil.h"

/* Retorna 1 se o caractere c é vogal (maiúscula ou minúscula) */
static int ehVogal(char c) {
    char vogais[] = "aeiouAEIOU";
    int i;
    for (i = 0; vogais[i] != '\0'; i++)
        if (c == vogais[i]) return 1;
    return 0;
}

int contaVogais(char *s) {
    int count = 0;
    while (*s != '\0') {
        if (ehVogal(*s)) count++;
        s++;
    }
    return count;
}

void inverteCString(char *s) {
    int len = (int)strlen(s);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp          = s[i];
        s[i]          = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int ePalindromo(char *s) {
    int len = (int)strlen(s);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return 0;
    }
    return 1;
}
