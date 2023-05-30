/* Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matr´ıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrura do tipo Aluno de computação
typedef struct
{
  int matricula;
  char nome[100];
  float prova[3];
} AlunoComputacao;

int main()
{

  int n;

  //le a quantidade de alunos do curso
  printf("Digite a quantidade de alunos do curso de computacao: ");
  scanf("%d", &n);

  AlunoComputacao alunos[n];
  float maiorNota1 = 0.0;

  for (int i = 0; i < n; i++)
  {float maiorNota1 = 0.0;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos[i].matricula);
    getchar();
    printf("Digite o nome: ");
    fgets(alunos[i].nome, 100, stdin);
    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

    for (int i = 0; i < 3; i++)
    {
      printf("Prova %d: ", i + 1);
      scanf("%f", &alunos[i].prova[i]);

    }
    if (alunos[i].prova[0] > maiorNota1)
    {
      maiorNota1 = alunos[i].prova[0];
    }
    
    printf("\n");
  }

  for (int i = 0; i < n; i++)
  {
    printf("Matricula: %d\n", alunos[i].matricula);
    printf("Nome: %s\n", alunos[i].nome);
    for (int i = 0; i < 3; i++)
    {
      printf("Nota %d: %.2f\n", i + 1, alunos[i].prova[i]);
    }
    printf("\n");
  }
  
  printf("Maior nota: %.f\n", maiorNota1);
  return 0;
}