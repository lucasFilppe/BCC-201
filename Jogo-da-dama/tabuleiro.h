/* tabuleiro.h
 *
 * Protótipos das funções do tabuleiro para o jogo de Damas.
 * Inclua este arquivo em damas.c e tabuleiro.c.
 *
 * Autor: SEU NOME
 * Matrícula: SEU NÚMERO
 */

#ifndef TABULEIRO_H
#define TABULEIRO_H

/* Inicializa o tabuleiro no estado inicial do jogo.
 * Parâmetro: t - matriz 8x8 que será preenchida.
 */
void inicializarTabuleiro(char t[8][8]);

/* Imprime o tabuleiro formatado (linhas A..H e colunas 1..8).
 * Observação: a função imprime a linha 0 como 'H' e a linha 7 como 'A' para
 * manter a visualização como no enunciado (H no topo).
 */
void imprimirTabuleiro(char t[8][8]);

/* Tenta executar uma jogada (movimento simples ou captura simples).
 * origem e destino são strings de 2 caracteres, ex: "C3" e "D4".
 * jogador é 'o' ou 'x'.
 * Retorno:
 *   0 = jogada inválida
 *   1 = movimento simples executado
 *   2 = captura executada
 */
int executarJogada(char t[8][8], char origem[3], char destino[3], char jogador);

/* Verifica se o jogo acabou (um jogador sem peças).
 * Retorna 1 se houve vencedor (um sem peças), 0 caso contrário.
 */
int verificarVencedor(char t[8][8]);

/* Salva o jogo em arquivo (mesmo formato esperado pelo enunciado).
 * arquivo: nome do arquivo
 * n1, n2: nomes dos jogadores
 * t: tabuleiro
 * jogador: jogador da vez ('o' ou 'x')
 */
void salvarJogo(const char *arquivo, const char *n1, const char *n2, char t[8][8], char jogador);

/* Carrega o jogo de arquivo. Se não conseguir abrir, finaliza com exit(1).
 * jogador é recebido por ponteiro para recuperar o jogador atual.
 */
void carregarJogo(const char *arquivo, char *n1, char *n2, char t[8][8], char *jogador);

/* Verifica se um movimento é uma captura simples (salto 2x2).
 * Recebe índices de matriz (li,ci -> lf,cf) e retorna 1 se é captura válida,
 * 0 caso contrário. Se for captura, *l_cap e *c_cap recebem a posição da peça capturada.
 */
int verificarCapturaSimples(char t[8][8], int li, int ci, int lf, int cf, char jogador, int *l_cap, int *c_cap);

#endif /* TABULEIRO_H */
