#include <stdio.h>

int main()
{
  int linha, coluna;
  printf("Movimentos de uma torre no xadrex\n");
  printf("Digite a linha em que a torre se encontra: ");
  scanf("%d", &linha);
  printf("Digite a coluna em que a torre se encontra: ");
  scanf("%d", &coluna);

  // imprime o cabeçalho da tabela antes do loop
  printf("\nMovimentos possiveis:\n");
  printf("       1   2   3   4   5   6   7   8   \n");
  printf("       -----------------------------\n");

  // imprime tabela
  for (int l = 1; l <= 8; l++)
  {
    printf("%4d  |", l);
    for (int c = 1; c <= 8; c++)
    {
      if (l == linha && c == coluna)
      {
        printf(" B  ");
      }
      // Diferença direta (diagonal principal do ponto)
      // OU Diferença invertida (diagonal secundária do ponto)
      else if ((l - linha == c - coluna) || (l - linha == -(c - coluna)))
      {
        printf(" x  ");
      }
      else
      {
        printf(" -  ");
      }
    }
    printf("\n");
  }
  return 0;
}