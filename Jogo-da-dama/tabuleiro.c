/* tabuleiro.c
 *
 * Implementação das funções do tabuleiro para o jogo de Damas.
 *
 * Observações importantes sobre convenção usada aqui:
 * - A matriz t[8][8] é indexada como t[linha][coluna], com linhas 0..7 e colunas 0..7.
 * - A função imprimirTabuleiro mostra a linha 0 como 'H' (topo) e a linha 7 como 'A' (embaixo),
 *   por isso usamos uma função de conversão consistente letra ↔ índice.
 *
 * Autor: SEU NOME
 * Matrícula: SEU NÚMERO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>      // para toupper()
#include "tabuleiro.h"

/* ---------------------------------------------------------
 * Auxiliar: converte letra de linha ('A'..'H' ou 'a'..'h')
 * para índice da matriz usada no programa.
 *
 * Retorno:
 *   -1 se letra inválida
 *   0..7 índice válido na matriz, onde:
 *     0 corresponde à linha H (topo na impressão)
 *     7 corresponde à linha A (embaixo na impressão)
 *
 * Isto garante que imprimirTabuleiro e a leitura de coordenadas
 * usem a mesma orientação.
 * --------------------------------------------------------- */
static int letraParaIndice(char L) {
    L = toupper((unsigned char)L);
    if (L < 'A' || L > 'H') return -1;
    return 'H' - L; // 'H'->0, 'G'->1, ..., 'A'->7
}

/* ---------------------------------------------------------
 * Inicializa o tabuleiro no estado padrão do enunciado.
 *
 * Layout esperado visualmente (linha H no topo):
 *
 * H x - x - x - x -
 * G - x - x - x - x
 * F x - x - x - x -
 * E - - - - - - - -
 * D - - - - - - - -
 * C o - o - o - o -
 * B - o - o - o - o
 * A o - o - o - o -
 *
 * Observação sobre paridade:
 * - Para as linhas 0..2 (H,G,F) colocamos 'x' quando (i+j)%2==0
 * - Para as linhas 5..7 (C,B,A) colocamos 'o' quando (i+j)%2==1
 * Isso produz a disposição correta das casas escuras conforme o enunciado.
 * --------------------------------------------------------- */
void inicializarTabuleiro(char tabuleiro[8][8]) {
    // Preenche todas as casas com '-'
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tabuleiro[i][j] = '-';

    // Coloca as peças PRETAS ('x') nas 3 primeiras linhas (topo)
    // Usamos a mesma paridade para as duas cores: (i + j) % 2 == 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 1) {
                tabuleiro[i][j] = 'x';
            }
        }
    }

    // Coloca as peças BRANCAS ('o') nas 3 últimas linhas (fundo)
    for (int i = 5; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 1) {
                tabuleiro[i][j] = 'o';
            }
        }
    }
}


/* ---------------------------------------------------------
 * Imprime o tabuleiro em formato legível:
 * - colunas 1..8 no topo e rodapé
 * - linhas H..A nas laterais (H no topo)
 * --------------------------------------------------------- */
void imprimirTabuleiro(char t[8][8]) {
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        // 'H' - i transforma i=0 -> 'H', i=7 -> 'A'
        printf("%c ", 'H' - i);
        for (int j = 0; j < 8; j++)
            printf("%c ", t[i][j]);
        printf("%c\n", 'H' - i);
    }
    printf("  1 2 3 4 5 6 7 8\n\n");
}

/* ---------------------------------------------------------
 * Verifica se um salto de 2x2 (diagonal) é uma captura válida.
 * - li,ci = origem (índices de matriz)
 * - lf,cf = destino (índices de matriz)
 * - jogador = 'o' ou 'x'
 * Se for captura válida retorna 1 e coloca em *l_cap,*c_cap a
 * posição da peça capturada.
 * --------------------------------------------------------- */
int verificarCapturaSimples(char t[8][8], int li, int ci, int lf, int cf, char jogador, int *l_cap, int *c_cap) {
    int di = lf - li;
    int dj = cf - ci;

    // Captura deve ser salto diagonal de 2 casas (±2, ±2)
    if (abs(di) != 2 || abs(dj) != 2) return 0;

    // Destino deve estar vazio
    if (t[lf][cf] != '-') return 0;

    // Posição do meio (peça a ser capturada)
    *l_cap = li + di / 2;
    *c_cap = ci + dj / 2;

    // Deve existir uma peça do adversário nessa casa do meio
    char meio = t[*l_cap][*c_cap];
    if (jogador == 'o' && meio == 'x') return 1;
    if (jogador == 'x' && meio == 'o') return 1;

    return 0;
}

/* ---------------------------------------------------------
 * Executa uma jogada: tentativa de captura primeiro, se não,
 * tentativa de movimento simples. Retorna 0/1/2 conforme descrito.
 *
 * Observação: as coordenadas de origem/destino chegam como strings
 * tipo "C3". A função aqui espera índices já convertidos como li,ci,lf,cf.
 * Porém o main passa strings ("C3"), e nesta função fazemos a conversão
 * usando letraParaIndice para manter consistência com a impressão.
 * --------------------------------------------------------- */
int executarJogada(char t[8][8], char origem[3], char destino[3], char jogador) {
    // converte letra -> índice (com a orientação usada na impressão)
    int li = letraParaIndice(origem[0]);
    int ci = origem[1] - '1';   // coluna 1..8 -> índice 0..7
    int lf = letraParaIndice(destino[0]);
    int cf = destino[1] - '1';

    // valida limites (qualquer coordenada inválida = jogada inválida)
    if (li < 0 || li > 7 || ci < 0 || ci > 7 || lf < 0 || lf > 7 || cf < 0 || cf > 7)
        return 0;

    // verifica se origem tem peça do jogador e destino está livre
    if (t[li][ci] != jogador || t[lf][cf] != '-')
        return 0;

    // posição da possível peça capturada (será preenchida pela função)
    int l_cap, c_cap;

    // tenta captura primeiro (obrigatório por regra; aqui simples: só uma captura)
    if (verificarCapturaSimples(t, li, ci, lf, cf, jogador, &l_cap, &c_cap)) {
        // executa a captura: move peça, limpa origem e peça capturada
        t[lf][cf] = jogador;
        t[li][ci] = '-';
        t[l_cap][c_cap] = '-';
        printf("Peca capturada na casa %c%d!\n", 'H' - l_cap, c_cap + 1);
        return 2; // captura
    }

    // movimento simples: diagonal 1x1
    int di = lf - li;
    int dj = cf - ci;
    if (abs(di) == 1 && abs(dj) == 1) {
        // Importante: com letraParaIndice, índices menores estão no topo (H).
        // Portanto, brancas ('o') que estão em baixo (linhas maiores) devem
        // avançar "para cima" nos índices: di == -1.
        // Pretas ('x') que estão no topo avançam "para baixo": di == +1.
        if (jogador == 'o' && di == -1) {
            t[lf][cf] = jogador;
            t[li][ci] = '-';
            return 1;
        }
        if (jogador == 'x' && di == 1) {
            t[lf][cf] = jogador;
            t[li][ci] = '-';
            return 1;
        }
    }

    // nenhuma regra atendida -> inválido
    return 0;
}

/* ---------------------------------------------------------
 * Salva o estado atual do jogo em arquivo texto.
 * Formato:
 * linha1: nome jogador1
 * linha2: nome jogador2
 * linhas 3..10: 8 linhas do tabuleiro (cada célula seguida por espaço)
 * última linha: jogador atual (caractere 'o' ou 'x')
 * --------------------------------------------------------- */
void salvarJogo(const char *arquivo, const char *n1, const char *n2, char t[8][8], char jogador) {
    FILE *f = fopen(arquivo, "w");
    if (!f) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    fprintf(f, "%s\n", n1);
    fprintf(f, "%s\n", n2);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            fprintf(f, "%c ", t[i][j]);
        fprintf(f, "\n");
    }

    fprintf(f, "%c\n", jogador);
    fclose(f);

    printf("Jogo salvo em %s\n", arquivo);
}

/* ---------------------------------------------------------
 * Carrega jogo de arquivo no mesmo formato usado por salvarJogo.
 * Em caso de erro (arquivo não encontrado) finaliza o programa com exit(1).
 * --------------------------------------------------------- */
void carregarJogo(const char *arquivo, char *n1, char *n2, char t[8][8], char *jogador) {
    FILE *f = fopen(arquivo, "r");
    if (!f) {
        printf("Erro ao abrir o arquivo %s para leitura.\n", arquivo);
        exit(1);
    }

    // lê nomes (assumimos no máximo 49 chars)
    fgets(n1, 50, f); n1[strcspn(n1, "\n")] = 0;
    fgets(n2, 50, f); n2[strcspn(n2, "\n")] = 0;

    // lê o tabuleiro (8x8)
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            fscanf(f, " %c", &t[i][j]);//le cada caractere do tabuleiro

    // lê jogador atual 'x' ou'o'
    fscanf(f, " %c", jogador);

    fclose(f);//fecha o arquivo
}

/* ---------------------------------------------------------
 * Verifica se algum jogador ficou sem peças => fim de jogo.
 * Retorna 1 se o jogo acabou (um jogador sem peças), 0 caso contrário.
 * --------------------------------------------------------- */
int verificarVencedor(char t[8][8]) {
    int o = 0, x = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (t[i][j] == 'o') o++;
            if (t[i][j] == 'x') x++;
        }
    if (o == 0 || x == 0) return 1;
    return 0;
}
