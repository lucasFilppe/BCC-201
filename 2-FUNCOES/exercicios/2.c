#include <stdio.h>

void classeEleitoral(int idade){
  if(idade < 16){
    printf("Nao-eleitor\n");
  }
  else if((idade >= 16 && idade < 18) || idade > 65) {
    printf("Eleitor facultativo\n");
  }
  else if(idade >= 18 && idade <= 65)
    printf("Eleitor obrigatorio\n");
}

int main(){
  int idade;

  printf("digite a idade: ");
  scanf("%d", &idade);

  classeEleitoral(idade);

  return 0;
}