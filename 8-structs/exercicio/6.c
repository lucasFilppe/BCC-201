/*. Fac¸a um programa que realize a leitura dos seguintes dados relativos a um conjunto de
alunos: Matricula, Nome, Codigo da Disciplina, Nota1 e Nota2. Considere uma turma de ´
ate 10 alunos. Ap ´ os ler todos os dados digitados, e depois de armazen ´ a-los em um vetor ´
de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas medias ´
finais (use uma media ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int matricula;
    char nome[100];
    int codigo;
    float notas[2];
}Alunos;

//caluculo de media ponderada


int main(){

    int n;
    float mediaPonderada = 0;

    //le quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    Alunos a[n];

    //le dados dos alunos
    for (int i = 0; i < n; i++)
    {
        printf("Digite a matricula: ");
        scanf("%d", &a[i].matricula);
        getchar();
        printf("Digite o nome: ");
        fgets(a[i].nome, 100, stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = '\0';
        printf("Digite o codigo: ");
        scanf("%d", &a[i].codigo);
        getchar();

        printf("Digite as notas das provas: ");
        scanf("%f", &a[i].notas[0], &a[i].notas[1]);

        mediaPonderada = ((1.0 * a[i].notas[0]) + (2.0 * a[i].notas[1]) / 2.0 + 1.0);    
        printf("\n");

    }

    for (int i = 0; i < n; i++)
    {
        printf("Matricula: %d\n", a[i].matricula);
        printf("Nome %s\n", a[i].nome);
        printf("Codigo: %d\n", a[i].codigo);
        printf("Nota %d = %.2f\n", i+1,a[i].notas[0]);
        printf("Nota %d = %.2f\n", i+1,a[i].notas[1]);
        
        printf("Media ponderada: %f\n", mediaPonderada);
        printf("\n");

    }
    
    
    return 0;
}