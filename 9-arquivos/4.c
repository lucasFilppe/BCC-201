#include <stdio.h>


 int main(int argc, char **argv)
{
  char c;
   FILE *entrada, *saida;

  entrada = fopen(argv[1], "r"); // primeiro argumento
  saida = fopen(argv[2], "w"); // segundo argumento
  while (!feof(entrada)) {
  c = fgetc(entrada);
  if (c != ' ' && c != EOF)
  fputc(c, saida);
  }
 fclose(entrada);
 fclose(saida);

 return 0;
 }