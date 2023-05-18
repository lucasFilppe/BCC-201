#include <stdio.h>

int main(){

    int ano;

    //le ano do usuario
    printf("Digite o ano: ");
    scanf("%d", &ano);

    //1° condiçaõ
    if( (ano % 4 == 0 && ano % 100 != 0) || (ano % 100 == 0 && ano % 400 == 0)){
        printf("O ano eh bisexto\n");
    }
    else
    {
        printf("nao eh um ano bissexto\n");
    }


}