/*-Nome: Antonio Neriah Pereira Ramos - RA:2040482522025
-Fatec Ipiranga - Ads Vespertino
-Atividade PEM - Aula 13 - Dia 21/05/2026
 * Programacao Estruturada e Modular
 * Fundamentos de Ponteiros em Linguagem C
 * Semana 13 — 2026/1
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 * SECAO 01 — Conceito e Definicao de Ponteiros
 * ============================================================ */

/*
 * Exercicio 01 — Endereco na Memoria
 * Para cada tipo (int, float, char), imprime:
 *   - o valor da variavel
 *   - o endereco da variavel (%p)
 *   - o endereco armazenado no ponteiro
 *   - o valor obtido via ponteiro (desreferenciacao)
 */
void exercicio01(void) {
    printf("=== Exercicio 01: Endereco na Memoria ===\n");

    int   vi = 42;
    float vf = 3.14f;
    char  vc = 'Z';

    int   *pi = &vi;
    float *pf = &vf;
    char  *pc = &vc;

    printf("\n-- int --\n");
    printf("  Valor da variavel   : %d\n",   vi);
    printf("  Endereco (&vi)      : %p\n",   (void *)&vi);
    printf("  Endereco no ponteiro: %p\n",   (void *)pi);
    printf("  Valor via ponteiro  : %d\n",   *pi);

    printf("\n-- float --\n");
    printf("  Valor da variavel   : %.2f\n", vf);
    printf("  Endereco (&vf)      : %p\n",   (void *)&vf);
    printf("  Endereco no ponteiro: %p\n",   (void *)pf);
    printf("  Valor via ponteiro  : %.2f\n", *pf);

    printf("\n-- char --\n");
    printf("  Valor da variavel   : %c\n",   vc);
    printf("  Endereco (&vc)      : %p\n",   (void *)&vc);
    printf("  Endereco no ponteiro: %p\n",   (void *)pc);
    printf("  Valor via ponteiro  : %c\n",   *pc);

    printf("\n");
}

/*
 * Exercicio 02 — Tamanho de um Ponteiro
 *
 * O tamanho de um ponteiro NAO varia com o tipo apontado.
 * Em arquiteturas de 64 bits, todo ponteiro ocupa 8 bytes;
 * em 32 bits, ocupa 4 bytes. O tipo so indica ao compilador
 * quantos bytes ler/escrever ao desreferenciar o ponteiro —
 * nao altera o tamanho do proprio ponteiro.
 */
void exercicio02(void) {
    printf("=== Exercicio 02: Tamanho de um Ponteiro ===\n");

    printf("  sizeof(int *)   : %zu bytes\n", sizeof(int *));
    printf("  sizeof(float *) : %zu bytes\n", sizeof(float *));
    printf("  sizeof(double *): %zu bytes\n", sizeof(double *));
    printf("  sizeof(char *)  : %zu bytes\n", sizeof(char *));

    /* Todos os ponteiros tem o mesmo tamanho na mesma arquitetura.
     * O tipo apontado so afeta a aritmetica (quanto avancar por ++)
     * e a desreferenciacao (quantos bytes interpretar), nunca o
     * tamanho do ponteiro em si. */

    printf("\n");
}

/* ============================================================
 * SECAO 02 — Operador de Referencia (&)
 * ============================================================ */

/*
 * Exercicio 03 — Troca de Valores via Referencia
 * A funcao recebe os enderecos de dois ints e troca seus valores.
 */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exercicio03(void) {
    printf("=== Exercicio 03: Troca de Valores via Referencia ===\n");

    int x = 10, y = 25;
    printf("  Antes : x = %d, y = %d\n", x, y);
    trocar(&x, &y);
    printf("  Depois: x = %d, y = %d\n", x, y);
    printf("\n");
}

/*
 * Exercicio 04 — Mapa de Enderecos de um Struct
 */
struct Aluno {
    char  nome[50];
    int   matricula;
    float media;
};

void exercicio04(void) {
    printf("=== Exercicio 04: Mapa de Enderecos de um Struct ===\n");

    struct Aluno a;
    strcpy(a.nome, "Maria Silva");
    a.matricula = 20261001;
    a.media     = 8.75f;

    printf("  Endereco de a           : %p\n", (void *)&a);
    printf("  Endereco de a.nome      : %p\n", (void *)&a.nome);
    printf("  Endereco de a.matricula : %p\n", (void *)&a.matricula);
    printf("  Endereco de a.media     : %p\n", (void *)&a.media);

    /*
     * Os campos sao alocados em ordem de declaracao, portanto seus
     * enderecos sao consecutivos (crescentes). O compilador pode
     * inserir bytes de padding entre campos para alinhar tipos maiores
     * (ex.: int em multiplo de 4 bytes), o que pode criar "lacunas"
     * entre enderecos. Aqui, 'nome' ocupa 50 bytes; 'matricula' (int)
     * pode comecar em offset 52 (com 2 bytes de padding) dependendo
     * do compilador/plataforma. Por isso os enderecos sao proximos,
     * mas nao necessariamente diff == sizeof(campo_anterior).
     */
    printf("\n");
}

/* ============================================================
 * SECAO 03 — Operador de Desreferenciacao (*)
 * ============================================================ */

/*
 * Exercicio 05 — Modificacao Indireta
 * Dobra cada elemento do vetor usando apenas '*' e aritmetica de ponteiros.
 */
void exercicio05(void) {
    printf("=== Exercicio 05: Modificacao Indireta ===\n");

    int v[5] = {3, 7, 12, 5, 9};
    int *p   = v;
    int i;

    printf("  Antes : ");
    for (i = 0; i < 5; i++) printf("%d ", *(p + i));
    printf("\n");

    /* Multiplica cada elemento por 2 sem usar [] */
    for (i = 0; i < 5; i++) *(p + i) *= 2;

    printf("  Depois: ");
    for (i = 0; i < 5; i++) printf("%d ", *(p + i));
    printf("\n\n");
}

/*
 * Exercicio 06 — Leitura e Escrita de Struct via Ponteiro
 */
struct Produto {
    char  nome[40];
    float preco;
    int   estoque;
};

void exercicio06(void) {
    printf("=== Exercicio 06: Leitura e Escrita de Struct via Ponteiro ===\n");

    struct Produto prod;
    struct Produto *pp = &prod;

    /* --- Usando * e . (sem ->) --- */
    strcpy((*pp).nome, "Caneta Azul");
    (*pp).preco   = 2.50f;
    (*pp).estoque = 100;

    printf("  [usando (*pp).campo]\n");
    printf("    Nome   : %s\n",   (*pp).nome);
    printf("    Preco  : %.2f\n", (*pp).preco);
    printf("    Estoque: %d\n",   (*pp).estoque);

    /* --- Usando -> (equivalente mais legivel) --- */
    strcpy(pp->nome, "Lapis Preto");
    pp->preco   = 1.20f;
    pp->estoque = 200;

    printf("  [usando pp->campo]\n");
    printf("    Nome   : %s\n",   pp->nome);
    printf("    Preco  : %.2f\n", pp->preco);
    printf("    Estoque: %d\n",   pp->estoque);

    /* (*pp).campo e pp->campo sao absolutamente equivalentes;
     * '->' e apenas uma notacao mais curta e legivel. */
    printf("\n");
}

/* ============================================================
 * SECAO 04 — Aritmetica de Ponteiros
 * ============================================================ */

/*
 * Exercicio 07 — Percurso com Incremento
 * Percorre o array com ponteiro, sem usar [].
 */
void exercicio07(void) {
    printf("=== Exercicio 07: Percurso com Incremento ===\n");

    int arr[8] = {14, 3, 22, 8, 17, 5, 30, 11};
    int *p     = arr;
    int soma   = 0, maior, menor;
    int i;

    maior = *p;
    menor = *p;

    for (i = 0; i < 8; i++) {
        printf("  arr[%d] = %2d  endereco: %p\n", i, *(p + i), (void *)(p + i));
        soma += *(p + i);
        if (*(p + i) > maior) maior = *(p + i);
        if (*(p + i) < menor) menor = *(p + i);
    }

    printf("  Soma  : %d\n",    soma);
    printf("  Media : %.2f\n",  (float)soma / 8);
    printf("  Maior : %d\n",    maior);
    printf("  Menor : %d\n",    menor);
    printf("\n");
}

/*
 * Exercicio 08 — Distancia entre Ponteiros
 */
void exercicio08(void) {
    printf("=== Exercicio 08: Distancia entre Ponteiros ===\n");

    double arr[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};

    double *p3 = arr + 2; /* aponta para o 3o elemento (indice 2) */
    double *p8 = arr + 7; /* aponta para o 8o elemento (indice 7) */

    /*
     * A diferenca entre dois ponteiros do mesmo tipo retorna ptrdiff_t:
     * o compilador subtrai os enderecos e divide pelo sizeof(double).
     * Resultado = (p8 - p3) = (endereco_p8 - endereco_p3) / sizeof(double).
     * Aqui: indices 7 - 2 = 5 elementos de distancia.
     */
    printf("  Distancia (p8 - p3): %td elementos\n", p8 - p3);

    printf("  Elementos entre p3 e p8 (inclusive):\n  ");
    double *p;
    for (p = p3; p <= p8; p++) printf("%.1f ", *p);
    printf("\n\n");
}

/* ============================================================
 * SECAO 05 — Ponteiros com Arrays
 * ============================================================ */

/*
 * Exercicio 09 — Inversao de Array com Ponteiros
 */
void inverter(int *arr, int n) {
    int *inicio = arr;
    int *fim    = arr + n - 1;
    int  temp;

    while (inicio < fim) {
        temp     = *inicio;
        *inicio  = *fim;
        *fim     = temp;
        inicio++;
        fim--;
    }
}

void exercicio09(void) {
    printf("=== Exercicio 09: Inversao de Array com Ponteiros ===\n");

    int v[7] = {10, 20, 30, 40, 50, 60, 70};
    int *p   = v;
    int  i;

    printf("  Antes : ");
    for (i = 0; i < 7; i++) printf("%d ", *(p + i));
    printf("\n");

    inverter(v, 7);

    printf("  Depois: ");
    for (i = 0; i < 7; i++) printf("%d ", *(p + i));
    printf("\n\n");
}

/*
 * Exercicio 10 — Busca em Matriz com Ponteiro
 * Percorre a matriz 4x4 como array linear; sem usar [i][j] no laco.
 */
void exercicio10(void) {
    printf("=== Exercicio 10: Busca em Matriz com Ponteiro ===\n");

    int mat[4][4] = {
        { 3, 17,  2, 11},
        {25,  8, 44,  6},
        { 1, 33, 19,  7},
        {12, 55,  4, 28}
    };

    int *p      = &mat[0][0]; /* ponteiro para o primeiro elemento */
    int  total  = 4 * 4;
    int  maior  = *p;
    int  idx    = 0;
    int  i;

    for (i = 0; i < total; i++) {
        if (*(p + i) > maior) {
            maior = *(p + i);
            idx   = i;
        }
    }

    printf("  Maior valor: %d\n",       maior);
    printf("  Posicao    : linha %d, coluna %d\n", idx / 4, idx % 4);
    printf("\n");
}

/* ============================================================
 * SECAO 06 — Passagem de Ponteiros em Funcoes
 * ============================================================ */

/*
 * Exercicio 11 — Funcao com Multiplos Retornos
 */
void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor) {
    int *p = v;
    int  i;

    *soma  = 0;
    *maior = *p;
    *menor = *p;

    for (i = 0; i < n; i++) {
        *soma += *(p + i);
        if (*(p + i) > *maior) *maior = *(p + i);
        if (*(p + i) < *menor) *menor = *(p + i);
    }
    *media = (float)*soma / n;
}

void exercicio11(void) {
    printf("=== Exercicio 11: Funcao com Multiplos Retornos ===\n");

    int   v[6] = {4, 15, 7, 22, 1, 13};
    int   soma, maior, menor;
    float media;

    estatisticas(v, 6, &soma, &media, &maior, &menor);

    printf("  Array : 4 15 7 22 1 13\n");
    printf("  Soma  : %d\n",    soma);
    printf("  Media : %.2f\n",  media);
    printf("  Maior : %d\n",    maior);
    printf("  Menor : %d\n",    menor);
    printf("\n");
}

/*
 * Exercicio 12 — Ordenacao por Selecao com Ponteiros
 * Selection Sort usando exclusivamente aritmetica de ponteiros.
 */
void imprimir_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");
}

void selectionSort(int *arr, int n) {
    int *i, *j, *min_ptr;
    int  troca = 0;

    for (i = arr; i < arr + n - 1; i++) {
        min_ptr = i;

        for (j = i + 1; j < arr + n; j++) {
            if (*j < *min_ptr) min_ptr = j;
        }

        if (min_ptr != i) {
            trocar(i, min_ptr);           /* reutiliza trocar() do Ex.03 */
            troca++;
            printf("    Troca %2d: ", troca);
            imprimir_array(arr, n);
        }
    }
}

void exercicio12(void) {
    printf("=== Exercicio 12: Ordenacao por Selecao com Ponteiros ===\n");

    int arr[8] = {64, 25, 12, 22, 11, 90, 3, 47};

    printf("  Antes    : ");
    imprimir_array(arr, 8);

    printf("  Trocas:\n");
    selectionSort(arr, 8);

    printf("  Depois   : ");
    imprimir_array(arr, 8);
    printf("\n");
}

/* ============================================================
 * MAIN — chama todos os exercicios em sequencia
 * ============================================================ */
int main(void) {
    exercicio01();
    exercicio02();
    exercicio03();
    exercicio04();
    exercicio05();
    exercicio06();
    exercicio07();
    exercicio08();
    exercicio09();
    exercicio10();
    exercicio11();
    exercicio12();
    return 0;
}
