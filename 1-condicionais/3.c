#include <stdio.h>

int main(){

  int num1, num2, num3, maior, menor, intermediario;

  printf("Digite os valores: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  //maior
  if (num1 > num2 && num1 > num3)
  {
     maior = num1;
  }
  if (num2 > num1 && num2 > num3)
  {
     maior = num2;
  }

  if (num3 > num1 && num3 > num2)
  {
     maior = num3;
  }

  //menor
  if (num1 < num2 && num1 < num3)
  {
     menor = num1;
  }
  if (num2 < num1 && num2 < num3)
  {
     menor = num2;
  }
  if (num3 < num1 && num3 < num2)
  {
     menor = num3;
  }

  //intermediario
  
  return 0;
}