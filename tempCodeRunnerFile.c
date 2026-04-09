#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

long explorarDiretorio(const char *caminho, int nivel) {
    DIR *dir;
    struct dirent *entrada;
    struct stat info;
    char novoCaminho[1024];
    long tamanhoTotal = 0;

    dir = opendir(caminho);
    if (dir == NULL) {
        printf("Erro ao abrir diretório: %s\n", caminho);
        return 0;
    }

    while ((entrada = readdir(dir)) != NULL) {

        // Ignorar . e ..
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0)
            continue;

        snprintf(novoCaminho, sizeof(novoCaminho), "%s/%s", caminho, entrada->d_name);

        if (stat(novoCaminho, &info) == 0) {

            // Indentação visual
            for (int i = 0; i < nivel; i++) printf("  ");

            if (S_ISDIR(info.st_mode)) {
                printf("[DIR] %s\n", entrada->d_name);

                long tamanhoSub = explorarDiretorio(novoCaminho, nivel + 1);
                tamanhoTotal += tamanhoSub;

                // Alerta de gargalo (ex: diretórios grandes)
                if (tamanhoSub > 10000000) { // 10 MB
                    for (int i = 0; i < nivel + 1; i++) printf("  ");
                    printf("⚠ ALERTA: Diretório grande (%ld bytes)\n", tamanhoSub);
                }

            } else {
                printf("%s (%ld bytes)\n", entrada->d_name, info.st_size);
                tamanhoTotal += info.st_size;
            }
        }
    }

    closedir(dir);
    return tamanhoTotal;
}

int main() {
    char caminho[1024];

    printf("Digite o caminho do diretório raiz: ");
    scanf("%s", caminho);

    long total = explorarDiretorio(caminho, 0);

    printf("\nTamanho total: %ld bytes\n", total);

    return 0;
}