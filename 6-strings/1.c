#include <stdio.h>
#include <string.h>

int main(){
    printf("Usuario, digite uma palavra: ");
    char palavra[100];
    scanf("%s", palavra);

    if(strcmp(palavra, "UFOP")== 0)
        printf("Bem vindo a Ouro preto\n");

    return 0;
}