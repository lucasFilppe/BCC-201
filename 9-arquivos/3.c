/*Crie um programa que conta o número de espaços em branco em um
arquivo passado como argumento. */

#include <stdio.h>

int main(int argc, char **argv)
{
  int nEspacos = 0;
  char c;
  FILE *arquivo;

  arquivo = fopen(argv[1], "r"); // argv[1] é o primeiro argumento
  while (!feof(arquivo)) {
      c = fgetc(arquivo);
      if (c == ' ') 
      nEspacos++;
  }

 fclose(arquivo);
 printf("O arquivo possui %d espaços.\n", nEspacos);
 return 0;
}