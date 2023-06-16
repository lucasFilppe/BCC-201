#include <stdio.h>

int main()
{

  FILE *arquivo = fopen("file2.txt", "r");

  // lendo um inteiro e um caractere separados por um espaço
  int inteiro;
  char caractere;
  fscanf(arquivo, "%d %c", &inteiro, &caractere);

  //mostrar no prompt o que tem no arquivo
  printf("%d %c\n", inteiro, caractere);

  fclose(arquivo);

  return 0;
}