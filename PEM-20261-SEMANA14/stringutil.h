/*
 * stringutil.h — Protótipos da biblioteca de operações com strings
 * Proibido usar funções de string.h exceto strlen.
 */

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

/* Conta vogais maiúsculas e minúsculas na string s */
int contaVogais(char *s);

/* Inverte a string s in-place */
void inverteCString(char *s);

/* Retorna 1 se s for palíndromo, 0 caso contrário */
int ePalindromo(char *s);

#endif /* STRINGUTIL_H */
