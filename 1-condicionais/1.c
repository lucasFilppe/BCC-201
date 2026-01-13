#include <stdio.h>

int main(){
    char letra;

    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    switch (letra)
    {
    case 'a':
    case 'A':
        printf("Eh uma vogal\n");
        break;
    case 'e':
    case 'E':
        printf("Eh uma vogal\n");
        break;
    case 'i' :
    case 'I':
        printf("Eh uma vogal\n");
        break;
    case 'o' :
    case 'O':
        printf("Eh uma vogal\n");
        break;
    case 'u' :
    case 'U' :
        printf("Eh uma vogal\n");
        break;
    
    default:
        printf("eH CONSOANTE\n");
        break;
    }
}