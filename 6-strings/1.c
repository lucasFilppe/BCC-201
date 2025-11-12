#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // argc é o número de argumentos passados.
    // O primeiro argumento (argv[0]) é sempre o nome do programa.
    // Então, precisamos de pelo menos 2 argumentos: nome_do_programa + a palavra a ser comparada.
    
    // Verifica se o número correto de argumentos foi fornecido
    if (argc < 2) {
        printf("Uso: ./nome_do_executavel <palavra_a_comparar>\n");
        return 1; // Retorna 1 para indicar erro
    }

    // O primeiro argumento fornecido pelo usuário está em argv[1]
    char *palavra_digitada = argv[1]; 
    
    // Compara a palavra digitada (argv[1]) com "UFOP"
    if (strcmp(palavra_digitada, "UFOP") == 0) {
        printf("Bem vindo a Ouro preto\n");
    } else {
        printf("Palavra digitada: %s. Nao e 'UFOP'.\n", palavra_digitada);
    }

    return 0;
}
