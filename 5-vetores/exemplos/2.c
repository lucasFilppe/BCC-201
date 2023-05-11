//Exemplo 2
//Ler n notas de alunos e imprimir quantas tem valor superior à média.
//Assuma que n ≤ 1000

#include <stdio.h>

// função para ler notas


//função para ler qunatidade de notas
void validaQuantidade(int n){

    if (n > 1000)
    {
        printf("Erro, a quantidade suportade é 1000 notas\n");
    }

    else{
        printf("Função para ler notas\n");
        
    }
    
    
}
int main(){


    int n;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &n);
    
    validaQuantidade(n);
    return 0;
}