#include <stdio.h>

void escreverMatrizArquivo(const char *nomeArquivo, int n, int m, int matriz[][100]) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d\n", n);
    fprintf(arquivo, "%d\n", m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

int main() {
    int n, m;
    int matriz[100][100];
    const char *nomeArquivo = "matriz.txt";

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    escreverMatrizArquivo(nomeArquivo, n, m, matriz);

    printf("Matriz escrita no arquivo com sucesso.\n");

    return 0;
}
