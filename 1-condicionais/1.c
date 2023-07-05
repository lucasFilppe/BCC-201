#include <stdio.h>

int main(){
    char letra;

    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    switch (letra)
    {
    case 'a'| 'A':
        printf("Eh uma vogal\n");
        break;
    case 'e' | 'E':
        printf("Eh uma vogal\n");
        break;
    case 'i' | 'I':
        printf("Eh uma vogal\n");
        break;
    case 'o' | 'O':
        printf("Eh uma vogal\n");
        break;
    case 'u' | 'U':
        printf("Eh uma vogal\n");
        break;
    
    default:
        printf("eH CONSOANTE\n");
        break;
    }
}