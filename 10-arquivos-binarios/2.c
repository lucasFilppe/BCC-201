#include <stdio.h>

void gravaVetor(int n, int *vetor, char path[])
{
  // declaração e carregamento do arquivo
  FILE *arquivo = fopen(path, "wb");

  // escrevendo o tamanho do vetor
  fwrite(&n, sizeof(int), 1, arquivo);

  // alocando e lendo o vetor (ou seja, sizeof(int) * n bytes)
  fwrite(vetor, sizeof(int), n, arquivo);

  // fechando o arquivo
  fclose(arquivo);
}

int main()
{
  int n = 10;
  int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  gravaVetor(n, vetor, "vetor.dat");
  return 0;
}