#ifndef TABULEIRO_H
#define TABULEIRO_H

// Função para criar o tabuleiro inicial
void inicializarTabuleiro(char t[8][8]);

// Exibe o tabuleiro na tela
void imprimirTabuleiro(char t[8][8]);

// Move uma peça de uma posição para outra (retorna 1 se válido, 0 se inválido)
int moverPeca(char t[8][8], char origem[3], char destino[3], char jogador);

// Salva o estado atual do jogo em um arquivo texto
void salvarJogo(const char *arquivo, const char *n1, const char *n2, char t[8][8], char jogador);

// Lê um arquivo texto e restaura o estado do jogo
void carregarJogo(const char *arquivo, char *n1, char *n2, char t[8][8], char *jogador);

// Verifica se algum jogador venceu (retorna 1 se o jogo acabou)
int verificarVencedor(char t[8][8]);

#endif