#include <stdio.h>
#include <string.h>

void substituir_caracteres(char* frase) {
    int i;
    int tamanho = strlen(frase);

    for (i = 0; i < tamanho; i++) {
        switch (frase[i]) {
            case 'a':
            case 'A':
                frase[i] = '@';
                break;
            case 'e':
            case 'E':
                frase[i] = ' ';
                break;
            case 'i':
            case 'I':
                frase[i] = '|';
                break;
            case 'o':
            case 'O':
                frase[i] = '0';
                break;
            case 'u':
            case 'U':
                frase[i] = '#';
                break;
            case 's':
            case 'S':
                frase[i] = '$';
                break;
            default:
                break;
        }
    }
}

int main() {
    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    substituir_caracteres(frase);

    printf("Frase substituída: %s\n", frase);

    return 0;
}
