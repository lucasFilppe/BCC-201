#include <stdio.h>

/* Esta função lê os dados de uma matriz; note que as dimensões da
2 * matriz são armazenadas nas variáveis n e m passadas por referência
3 */
void lerMatrizArquivo(const char arquivo[], int matriz[100][100], int *n, int *m)
{
  FILE *entrada = fopen(arquivo, "r");

  fscanf(entrada, "%d", n);
  fscanf(entrada, "%d", m);
  
  for (int i = 0; i < *n; i++) {
      for (int j = 0; j < *m; j++)
        fscanf(entrada, "%d", &matriz[i][j]);
  }

  fclose(entrada);
}

int main(int argc, char **argv){

  int n, m;
    int matriz[100][100];
    const char *nomeArquivo = "matriz1.txt";

    lerMatrizArquivo(nomeArquivo, matriz, &n, &m);

    printf("Matriz lida:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
  return 0;
}