#include <stdio.h>

typedef struct{
    char nome[100];
    float altura;
    int anoNascimento;
}NovaPessoa; 

//função para inserir uma pessoa
void inserirPessoa(NovaPessoa p){
    getchar();

    printf("Digite o nome da pessoa: ");
    fgets(p.nome, 100, stdin);
    printf("Digite a altura da pessoa: ");
    scanf("%f", &p.altura);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &p.anoNascimento);
    printf("\n\n");
}

void listarNomesAlturas(NovaPessoa p[]){

}

int main(){

    int opcao;
    NovaPessoa novapessoa;

    //menu de opções
    do
    {
        /* code */
        printf("(1) inserir uma nova pessoa: nome, altura e ano de nascimeto\n");
        printf("(2) listar todos os nomes e respectivas alturas\n");
        printf("(3) listar os nomes das pessoas que nasceram depois de um certo ano\n");
        printf("(0) para fechar programa\n\n");

        printf("Digite a Opçao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirPessoa(novapessoa);
            break;
        
        default:
            break;
        }

    } while (opcao != 0);
    
    

    return 0;
}