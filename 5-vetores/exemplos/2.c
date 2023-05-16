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
        lerNotas(n);
        
    }   
}

void lerNotas(int n){
    float  nota[n], soma = 0;
    for(int i=0; i<n; i++){
        printf("Digite a %d nota: ", i + 1);
        scanf("%d", &nota[i]);

        if(nota[i] >= 0 && nota[i] <= 10){
            soma += nota[i];
        }
        else{
            printf("Nota invalida\n");
            printf("Digite a %d nota: ", i + 1);
            scanf("%d", &nota[i]);
        }
        printf("\n")
    }
}
int main(){


    int n;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &n);
    
    validaQuantidade(n);
    return 0;
}