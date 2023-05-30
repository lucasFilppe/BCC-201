// Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
//armazene os dados em uma estrutura.
#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    char endereco[100];
}Dadospessoa;

//função que le dados de uma pessoa
Dadospessoa pessoa(){
    Dadospessoa p;

    printf("Digite seu nome: ");
    fgets(p.nome, 100, stdin);
    printf("Digite sua idade: ");
    scanf("%d", &p.idade);
    getchar();
    printf("Digite seu endereco: ");
    fgets(p.endereco, 100, stdin);

    return p;
}

int main(){
    Dadospessoa people;

    people = pessoa();

    printf("\n");
    printf("%s", people.nome);
    printf("%d\n", people.idade);
    printf("%s\n", people.endereco);

    return 0;
}