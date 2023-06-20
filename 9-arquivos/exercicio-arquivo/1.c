#include <stdio.h>

void lerMatrizArquivo(const char *nomeArquivo, int *n, int *m, int matriz[][100]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fscanf(arquivo, "%d", n);
    fscanf(arquivo, "%d", m);

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    fclose(arquivo);
}

void imprimirMatrizInversa(int n, int m, int matriz[][100]) {
    printf("Inverso da matriz:\n");
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    int matriz[100][100];
    const char *nomeArquivo = "matriz1.txt";

    lerMatrizArquivo(nomeArquivo, &n, &m, matriz);

    imprimirMatrizInversa(n, m, matriz);

    return 0;
}
