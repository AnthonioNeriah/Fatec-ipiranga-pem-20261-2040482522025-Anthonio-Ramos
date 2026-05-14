#ifndef INTERFACE_H
#define INTERFACE_H

// Exibe o menu principal e retorna a opção escolhida
int exibirMenu(void);

// Lê um inteiro do usuário com mensagem personalizada
int lerInteiro(const char *mensagem);

// Exibe o resultado de uma operação
void exibirResultado(const char *operacao, long long resultado);

// Limpa o buffer de entrada
void limparBuffer(void);

#endif
