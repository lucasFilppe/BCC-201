/*Construa uma estrutura aluno com nome, numero de matr ´ ´ıcula e curso. Leia do usuario ´
a informac¸ao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na ˜
tela. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura do tipon aluno
typedef struct {
  char nome[100];
  int matricula;
  char curso[50];
} Aluno;

//retorna dados do aluno
Aluno dadosAluno() {
  Aluno p;

  printf("Digite o nome do aluno: ");
  fgets(p.nome, 100, stdin);
  p.nome[strcspn(p.nome, "\n")] = '\0';//remover nova linha à direita

  printf("Digite a matricula do aluno: ");
  scanf("%d", &p.matricula);
  getchar(); // consome o caractere de nova linha

  printf("Digite o curso: ");
  fgets(p.curso, 50, stdin);
  p.curso[strcspn(p.curso, "\n")] = '\0';//remover nova linha à direita

  printf("\n\n");

  return p;
}

int main() {
  Aluno pessoa[5];

  for (int i = 0; i < 5; i++) {
    pessoa[i] = dadosAluno();
  }

  for (int i = 0; i < 5; i++) {
    printf("Aluno: %s\n", pessoa[i].nome);
    printf("Matricula: %d\n", pessoa[i].matricula);
    printf("Curso: %s\n", pessoa[i].curso);
    printf("\n");
  }

  return 0;
}