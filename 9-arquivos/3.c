/*Crie um programa que conta o número de espaços em branco em um
arquivo passado como argumento. */

#include <stdio.h>

int main(int argc, char **argv)
{
  int nEspacos = 0;
  char c;
  FILE *arquivo;

  arquivo = fopen(argv[1], "r"); // argv[1] é o primeiro argumento
 
  //se for diferente de final de arquivo
  while (!feof(arquivo)) {
      c = fgetc(arquivo);//le caractere e retorna seu numero da tabela ACIII
      if (c == ' ') 
      nEspacos++;
  }

 fclose(arquivo);
 printf("O arquivo possui %d espaços.\n", nEspacos);
 return 0;
}