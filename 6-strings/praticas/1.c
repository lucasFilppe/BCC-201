
/* Fa¸ca um programa que leia o nome completo de uma pessoa com at´e 70 caracteres. Em seguida,
impri70ma o ´ultimo sobrenome e nome (veja o exemplo abaixo) e a quantidade total de letras do nome
e do ´ultimo sobrenome.*/

#include <stdio.h>
#include <string.h>

int main() {
    char nome_completo[71];
    char ultimo_sobrenome[71];
    char nome[71];
    int quantidade_total_letras = 0;

    printf("Digite o nome completo: ");
    fgets(nome_completo, sizeof(nome_completo), stdin);
    nome_completo[strcspn(nome_completo, "\n")] = '\0'; // Remove a quebra de linha da entrada

    // Encontra o último sobrenome
    char *sobrenome = strrchr(nome_completo, ' ');
    if (sobrenome != NULL) {
        strcpy(ultimo_sobrenome, sobrenome + 1);
        *sobrenome = '\0';
    } else {
        strcpy(ultimo_sobrenome, nome_completo);
        strcpy(nome, nome_completo);
    }

    // Encontra o nome (excluindo o último sobrenome)
    if (sobrenome != NULL) {
        strcpy(nome, nome_completo);
    } else {
        nome[0] = '\0';
    }

    // Calcula a quantidade total de letras do nome completo e do último sobrenome
    for (int i = 0; nome_completo[i] != '\0'; i++) {
        if (nome_completo[i] != ' ') {
            quantidade_total_letras++;
        }
    }

    printf("Último sobrenome: %s\n", ultimo_sobrenome);
    printf("Nome: %s\n", nome);
    printf("Quantidade total de letras: %d\n", quantidade_total_letras);

    return 0;
}
