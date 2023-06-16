#include <stdio.h>

typedef struct{
    char nome[100];
    float altura;
    int anoNascimento;
}NovaPessoa; 

//função para inserir uma pessoa
NovaPessoa inserirPessoa(){
    getchar();

    NovaPessoa p;
    printf("Digite o nome da pessoa: ");
    fgets(p.nome, 100, stdin);
    printf("Digite a altura da pessoa: ");
    scanf("%f", &p.altura);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &p.anoNascimento);
    printf("\n\n");

    return p;
}

void listarNomesAlturas(NovaPessoa p[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s, altura %f\n", p[i].nome, p[i].altura);
        printf("\n");
    }
    printf("\n\n");
}

void listarPessoasAno(NovaPessoa p[], int n){
    for (int i = 0; i < n; i++)
    {
        //se nascer depois de um certpo ano
        if(p[i].ano >= 2000){
            printf("Nome: %s, GERACAO NUTELLA\n", p[i].nome);
            printf("\n");
        }
    }
    
}

int main(){

    int opcao;
    int n = 0;
    NovaPessoa novapessoa[50];

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
            novapessoa[n] = inserirPessoa();
            n++;
            break;
        case 2:
            listarNomesAlturas(novapessoa, n);
        
        case 3:
            listarPessoasAno(novapessoa, n);
        default:
            break;
        }

    } while (opcao != 0);
    
    

    return 0;
}