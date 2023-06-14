/* Fa¸ca um programa que leia o nome completo de uma pessoa com at´e 70 caracteres. Em seguida,
impri70ma o ´ultimo sobrenome e nome (veja o exemplo abaixo) e a quantidade total de letras do nome
e do ´ultimo sobrenome.*/

#include <stdio.h>


//função que verifica o tamnho da string menos os espaços e o caractere de \n
void totalLetrasNome(char *nome){
  int tamanho = 0;
  int i = 0;
  int j = 0;
  char espaco[70];

  while(nome[i] != '\0'){
    if(nome[i] != ' ' && nome[i] != '\n'){
      tamanho++;
  }
  printf("Tamanho da string digitada sem espaços e barra n: %d\n", tamanho);

  //verificar tamanho do ultimo nome
  for (int i = 0; i < tamanho; i++)
  {
    
    if(nome[i] == ' '){
      espaco[j] = nome[i];
    }
  }
  
}



//função para verificar espaços

int main(){

  char nome[70]; //declara um vetor de char de 70 cagitracteres

  //le nome
  printf("Digite um nome completo: ");
  fgets(nome, 70, stdin);

  //verifica tamanho da string
  int i = 0;
  int tamanho = 0;

  while(nome[i] != '\0'){
    tamanho++;
    i++;
  }
  printf("Tamanho da string digitada: %d\n", tamanho);

  totalLetrasNome(nome);

  
  
  return 0;
}