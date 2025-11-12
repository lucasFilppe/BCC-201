#include <stdio.h>
#include <string.h>
#include "tabuleiro.h" 
#include "stdlib.h"

void inicializarTabuleiro(char tabuleiro[8][8]) {
    // Preenche todas as casas com '-'
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tabuleiro[i][j] = '-';
    
    //coloca as peças 'o'nas 3 primeiras linhas
    /*percorre as 24 posições iniciais destinadas às peças 
    brancas (3 linhas $\times$ 8 colunas) e, usando a regra da
     paridade de índices, coloca uma peça 'o' em exatamente 
     metade delas (as 12 casas escuras), 
     seguindo as regras de início do jogo8888.*/
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) 
          if ((i + j) % 2 == 1) {
            //printf("colocando peça branca em %d %d\n", i, j);
            tabuleiro[i][j] = 'o';
          }
    }

    // Coloca as peças 'x' (pretas) nas 3 últimas linhas
    for (int i = 5; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((i + j) % 2 == 0) 
              tabuleiro[i][j] = 'x';
             
}

void imprimirTabuleiro(char t[8][8]) {
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%c ", 'A' + i); // linha (A, B, C, ...)
        for (int j = 0; j < 8; j++)
            printf("%c ", t[i][j]);
        printf("%c\n", 'A' + i);
    }
    printf("  1 2 3 4 5 6 7 8\n\n");
}

// =======================================================================
// Move uma peça simples (sem capturas e sem damas)
// Retorna 1 se o movimento for válido, 0 se inválido
// =======================================================================
int moverPeca(char t[8][8], char origem[3], char destino[3], char jogador) {
    // Converte a posição de letra/número para índices da matriz
    int li = origem[0] - 'A';  // linha inicial
    int ci = origem[1] - '1';  // coluna inicial
    int lf = destino[0] - 'A'; // linha final
    int cf = destino[1] - '1'; // coluna final

    // Verifica se está dentro dos limites do tabuleiro
    if (li < 0 || li > 7 || ci < 0 || ci > 7 || lf < 0 || lf > 7 || cf < 0 || cf > 7)
        return 0;

    // Verifica se a casa inicial contém a peça do jogador e destino está livre
    if (t[li][ci] != jogador || t[lf][cf] != '-') return 0;

    // Calcula a diferença entre as coordenadas
    int di = lf - li;
    int dj = cf - ci;

    // ===== Movimento das brancas ("o") — apenas para frente (↓)
    if (jogador == 'o' && di == 1 && abs(dj) == 1) {
        t[lf][cf] = jogador;  // coloca a peça no destino
        t[li][ci] = '-';      // apaga da posição anterior
        return 1;
    }

    // ===== Movimento das pretas ("x") — apenas para frente (↑)
    if (jogador == 'x' && di == -1 && abs(dj) == 1) {
        t[lf][cf] = jogador;
        t[li][ci] = '-';
        return 1;
    }

    // Se não for nenhum desses movimentos válidos
    return 0;
}

// =======================================================================
// Salva o jogo atual em um arquivo texto
// =======================================================================
void salvarJogo(const char *arquivo, const char *n1, const char *n2, char t[8][8], char jogador) {
    FILE *f = fopen(arquivo, "w");
    if (!f) return; // erro ao abrir o arquivo

    // Escreve os nomes dos jogadores
    fprintf(f, "%s\n%s\n", n1, n2);

    // Escreve o tabuleiro (8 linhas)
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            fprintf(f, "%c ", t[i][j]);
        fprintf(f, "\n");
    }

    // Escreve quem é o jogador atual
    fprintf(f, "%c\n", jogador);

    fclose(f);
    printf("Jogo salvo em %s\n", arquivo);
}

// =======================================================================
// Carrega um jogo salvo de um arquivo texto
// =======================================================================
void carregarJogo(const char *arquivo, char *n1, char *n2, char t[8][8], char *jogador) {
    FILE *f = fopen(arquivo, "r");
    if (!f) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Lê os nomes dos jogadores
    fgets(n1, 50, f); n1[strcspn(n1, "\n")] = 0;
    fgets(n2, 50, f); n2[strcspn(n2, "\n")] = 0;

    // Lê o tabuleiro (8 linhas, 8 colunas)
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            fscanf(f, " %c", &t[i][j]);

    // Lê quem joga agora
    fscanf(f, " %c", jogador);

    fclose(f);
}

// =======================================================================
// Verifica se algum jogador ficou sem peças (fim de jogo)
// =======================================================================
int verificarVencedor(char t[8][8]) {
    int o = 0, x = 0;

    // Conta as peças de cada jogador
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (t[i][j] == 'o') o++;
            if (t[i][j] == 'x') x++;
        }

    // Se um jogador não tem mais peças, o jogo acabou
    if (o == 0 || x == 0) return 1;

    return 0;
}