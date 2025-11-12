// =======================================================================
// Nome: SEU NOME AQUI
// Matrícula: SEU NÚMERO
// Trabalho: Jogo de Damas (versão simples)
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabuleiro.h"  // inclui as funções auxiliares

int main() {
    char opcao[10];          // armazena se o usuário quer novo jogo ou continuar
    char nome1[50], nome2[50]; // nomes dos jogadores
    char arquivo[50];         // nome do arquivo de salvamento
    char jogadorAtual = 'o';  // 'o' = peças brancas, sempre começa
    char tab[8][8];           // matriz que representa o tabuleiro 8x8

    // ======= MENU INICIAL =======
    printf("Bem-vindo ao Jogo de Damas!\n");
    printf("1 - Novo jogo\n");
    printf("2 - Continuar jogo\n");
    printf("Escolha: ");
    scanf("%s", opcao);

    // ======= CARREGAR JOGO EXISTENTE =======
    if (strcmp(opcao, "2") == 0) {
        printf("Nome do arquivo: ");
        scanf("%s", arquivo);
        // Lê o arquivo e restaura o estado do jogo
        carregarJogo(arquivo, nome1, nome2, tab, &jogadorAtual);
    } 
    // ======= NOVO JOGO =======
    else {
        printf("Nome do jogador 1 (brancas): ");
        scanf(" %[^\n]", nome1); // lê com espaço
        printf("Nome do jogador 2 (pretas): ");
        scanf(" %[^\n]", nome2);
        inicializarTabuleiro(tab); // cria o tabuleiro padrão
    }

    // Mostra o tabuleiro inicial ou carregado
    imprimirTabuleiro(tab);

    // ======= LOOP PRINCIPAL DO JOGO =======
    char jogada[5], destino[5]; // exemplo: "C3" "D4"
    while (1) {
        printf("%s (%c), digite sua jogada (ex: C3 D4) ou 'salvar'/'sair': ",
               (jogadorAtual == 'o') ? nome1 : nome2, jogadorAtual);
        scanf("%s", jogada);

        // ======= COMANDO SAIR =======
        if (strcmp(jogada, "sair") == 0) break;

        // ======= COMANDO SALVAR =======
        if (strcmp(jogada, "salvar") == 0) {
            printf("Nome do arquivo: ");
            scanf("%s", arquivo);
            salvarJogo(arquivo, nome1, nome2, tab, jogadorAtual);
            continue;
        }

        // ======= LER DESTINO DA JOGADA =======
        scanf("%s", destino);

        // ======= TENTA MOVER A PEÇA =======
        if (moverPeca(tab, jogada, destino, jogadorAtual)) {
            // troca o jogador
            jogadorAtual = (jogadorAtual == 'o') ? 'x' : 'o';
        } else {
            printf("Jogada invalida!\n");
        }

        // mostra o tabuleiro atualizado
        imprimirTabuleiro(tab);

        // ======= VERIFICA SE O JOGO TERMINOU =======
        if (verificarVencedor(tab)) {
            printf("Fim de jogo! Vencedor: %s\n",
                   (jogadorAtual == 'x') ? nome1 : nome2);
            break;
        }
    }

    printf("Tchau!\n");
    return 0;
}
