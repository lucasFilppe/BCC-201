#include <stdio.h>

int letra_Minuscula_Maiuscula(char caractere){
  //97 a 122 minuscula
  if ((int)caractere >= 97 &&  (int)caractere <= 122 )
    return 1;

  else if ((int)caractere >= 65 &&  (int)caractere <= 90 )
    return 0;
  
  return -1;
}

int main(){

  char letra;

  printf("Digite uma letra qualquer: ");
  scanf(" %c", &letra);

  if(letra_Minuscula_Maiuscula(letra) == 1){
    printf("Letra minuscula\n");
  }
  else if(letra_Minuscula_Maiuscula(letra) == 0){
    printf("Letra maiuscula\n");
  }
  else
    printf("O caracter não e uma letra\n");
  return 0;
}