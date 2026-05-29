/*-Nome: Anthonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 14 - Dia 28/05/2026
 * Programacao Estruturada e Modular
 * Semana 14 — 2026/1
 */
#include <stdio.h>
#include "stringutil.h"

int main(void) {
    printf("=== Biblioteca de Operações com Strings ===\n\n");

    /* --- contaVogais --- */
    char s1[] = "Programacao Estruturada";
    char s2[] = "rythm";
    printf("contaVogais(\"%s\") = %d\n", s1, contaVogais(s1));
    printf("contaVogais(\"%s\") = %d\n\n", s2, contaVogais(s2));

    /* --- inverteCString --- */
    char s3[] = "FATEC";
    char s4[] = "linguagem C";
    printf("inverteCString(\"%s\") → ", s3);
    inverteCString(s3);
    printf("\"%s\"\n", s3);

    printf("inverteCString(\"%s\") → ", s4);
    inverteCString(s4);
    printf("\"%s\"\n\n", s4);

    /* --- ePalindromo --- */
    char s5[] = "arara";
    char s6[] = "computador";
    printf("ePalindromo(\"%s\") = %d (esperado: 1)\n", s5, ePalindromo(s5));
    printf("ePalindromo(\"%s\") = %d (esperado: 0)\n", s6, ePalindromo(s6));

    return 0;
}
