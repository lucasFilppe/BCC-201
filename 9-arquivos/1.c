#include <stdio.h>

int main(){
  int inteiro = 26;
  char palavra[10] = "idade";

  // declaração e carregamento do arquivo
  FILE *arquivo = fopen("file.txt", "w");

  // gravando um inteiro e uma palavra no arquivo
  fprintf(arquivo, "%s - %d\n", palavra, inteiro);

  // fechando (e salvando) o arquivo
  fclose(arquivo);
  return 0;
}