#include <stdio.h>

int main()
{
  int inteiro = 10;
  char palavra[10] = "Palavra";

  // declaração e carregamento do arquivo
  FILE *arquivo = fopen("file.dat", "wb");

  // escrevendo sizeof(int) * 1 bytes no arquivo
  fwrite(&inteiro, sizeof(int), 1, arquivo);
  // escrevendo sizeof(char) * 10 bytes no arquivo
  fwrite(palavra, sizeof(char), 10, arquivo);

  // fechando (e salvando) o arquivo
  fclose(arquivo);
  return 0;
}