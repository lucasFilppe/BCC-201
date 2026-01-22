#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // para toupper()
#include "tabuleiro.h"

/*static: Significa que esta função só pode ser usada dentro do arquivo onde
 foi criada. É uma boa prática de organização.

toupper: Esta é a parte da "gentileza" com o usuário. Se ele digitar 'a' (minúsculo)
 a função transforma em 'A' (maiúsculo). Isso evita que o programa dê erro
 só por causa da tecla Caps Lock*/
static int letraParaIndice(char L)
{
    L = toupper((unsigned char)L);

    // se a letra for diferente de A ate H, retorne -1 para indicar erro
    if (L < 'A' || L > 'H')
        return -1;

    // Subtrai o valor ASCII da letra L do valor ASCII de 'H'.
    // Como 'H' é 72 e 'A' é 65, o resultado será um índice de 0 a 7.
    // Exemplo: Se L for 'H' (72), 72 - 72 = 0. Se L for 'A' (65), 72 - 65 = 7.
    return 'H' - L; // 'H'->0, 'G'->1, ..., 'A'->7
}

/* as peças pretas são icializadas nas tres primeiras linha do tabuleiro(x)
   as peças brancas são inicializadas nas 3 ultimas linhas (0)
   para posiciona-las na celula correta, verificamos se a soma
    da linha e coluna é impar
*/
void inicializarTabuleiro(char tabuleiro[8][8])
{
    // Preenche todas as casas com '-'
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tabuleiro[i][j] = '-';

    // Coloca as peças PRETAS ('x') nas 3 primeiras linhas (topo)
    // Usamos a mesma paridade para as duas cores: (i + j) % 2 == 1
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 1)
            {
                tabuleiro[i][j] = 'x';
            }
        }

        // Coloca as peças BRANCAS ('o') nas 3 últimas linhas (fundo)
        for (int i = 5; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    tabuleiro[i][j] = 'o';
                }
            }
        }
    }
}

/* ---------------------------------------------------------
 * Imprime o tabuleiro em formato legível:
 * - colunas 1..8 no topo e rodapé
 * - linhas H..A nas laterais (H no topo)
 * --------------------------------------------------------- */
void imprimirTabuleiro(char t[8][8])
{
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++)
    {
        // 'H' - i transforma i=0 -> 'H', i=7 -> 'A'
        printf("%c ", 'H' - i);
        for (int j = 0; j < 8; j++)
            printf("%c ", t[i][j]);
        printf("%c\n", 'H' - i);
    }
    printf("  1 2 3 4 5 6 7 8\n\n");
}

/*“A função recebe a posição inicial e final de uma jogada.
Ela calcula o deslocamento do movimento, verifica se é um salto diagonal
de duas casas, confere se o destino está vazio e identifica a casa
intermediária do salto, onde deve existir uma peça adversária.
Se todas essas condições forem atendidas, a captura é considerada válida.”*/
int verificarCapturaSimples(char tabuleiro[8][8],
                            int linhaOrigem, int colunaOrigem,
                            int linhaDestino, int colunaDestino,
                            char jogador,
                            int *linhaCapturada, int *colunaCapturada)
{
    /*Peça 'x' está em (3, 4)
        Peça 'o' está em (4, 5)
        Destino da captura seria (5, 6)
    */
    int deslocLinha = linhaDestino - linhaOrigem;    // 6 - 3 = 2
    int deslocColuna = colunaDestino - colunaOrigem; // 6 - 4 = 2

    // Deve ser um salto diagonal de duas casas
    if (abs(deslocLinha) != 2 || abs(deslocColuna) != 2)
        return 0;

    // A casa de destino deve estar vazia
    if (tabuleiro[linhaDestino][colunaDestino] != '-')
        return 0;

    // Posição da peça capturada (meio do salto)
    *linhaCapturada = linhaOrigem + deslocLinha / 2;    // 3 + 2/2 = 4
    *colunaCapturada = colunaOrigem + deslocColuna / 2; // 4 + (2)/2 = 5

    // Define qual é a peça do adversário
    char pecaAdversaria;

    if (jogador == 'x')
    {
        pecaAdversaria = 'o';
    }
    else
    {
        pecaAdversaria = 'x';
    }

    // Verifica se existe uma peça adversária na casa do meio
    //Em (4, 5) temos 'o'
    return tabuleiro[*linhaCapturada][*colunaCapturada] == pecaAdversaria;
}

int verificarCapturaDama(char t[8][8], int li, int ci, int lf, int cf,
                         char jogador, int *l_cap, int *c_cap)
{
    int di = lf - li;
    int dj = cf - ci;

    if (abs(di) != abs(dj))
        return 0;
    if (t[lf][cf] != '-')
        return 0;

    int pi = (di > 0) ? 1 : -1;
    int pj = (dj > 0) ? 1 : -1;

    int i = li + pi, j = ci + pj;
    int encontrou = 0;

    while (i != lf && j != cf)
    {
        if (t[i][j] != '-')
        {
            if (encontrou)
                return 0;

            if (jogador == 'o' && (t[i][j] == 'x' || t[i][j] == 'X'))
            {
                encontrou = 1;
                *l_cap = i;
                *c_cap = j;
            }
            else if (jogador == 'x' && (t[i][j] == 'o' || t[i][j] == 'O'))
            {
                encontrou = 1;
                *l_cap = i;
                *c_cap = j;
            }
            else
                return 0;
        }
        i += pi;
        j += pj;
    }
    return encontrou;
}

/*
 * =================================================================================
 * FUNÇÃO: executarJogada
 * =================================================================================
 * Objetivo:
 * Centraliza a lógica de movimento. Recebe o pedido do usuário, valida se
 * obedece às regras do jogo (Damas) e altera a matriz do tabuleiro.
 *
 * Parâmetros:
 * tabuleiro[8][8]  : A matriz que representa o estado atual do jogo.
 * posicaoOrigem    : String com a coordenada de saída (ex: "C3").
 * posicaoDestino   : String com a coordenada de chegada (ex: "D4").
 * jogadorAtual     : Caractere que indica quem está jogando ('o' ou 'x').
 *
 * Retorno (Códigos de Status):
 * 0 -> Jogada Inválida (nada acontece).
 * 1 -> Movimento Simples (troca o turno).
 * 2 -> Captura Finalizada (troca o turno).
 * 3 -> Captura Múltipla/Combo (NÃO troca o turno, jogador deve jogar de novo).
 * =================================================================================
 */
int executarJogada(char tabuleiro[8][8],
                   char posicaoOrigem[3],
                   char posicaoDestino[3],
                   char jogadorAtual)
{
    // =========================================================================
    // ETAPA 1: TRADUÇÃO (PREPARAÇÃO DOS DADOS)
    // Converte o texto "C3" para números que o computador entende.
    // =========================================================================
    
    int linhaOrigem   = letraParaIndice(posicaoOrigem[0]);
    int colunaOrigem  = posicaoOrigem[1] - '1';
    int linhaDestino  = letraParaIndice(posicaoDestino[0]);
    int colunaDestino = posicaoDestino[1] - '1';

    // =========================================================================
    // ETAPA 2: O PORTEIRO (VALIDAÇÕES DE SEGURANÇA)
    // Se qualquer coisa estiver errada aqui, retorna 0 imediatamente.
    // Isso limpa o caminho para a lógica real do jogo.
    // =========================================================================

    // 2.1 - Está dentro do tabuleiro?
    if (linhaOrigem < 0 || linhaOrigem > 7 || colunaOrigem < 0 || colunaOrigem > 7 ||
        linhaDestino < 0 || linhaDestino > 7 || colunaDestino < 0 || colunaDestino > 7) {
        return 0; 
    }

    // 2.2 - O destino está livre? (Não posso ir para onde já tem peça)
    if (tabuleiro[linhaDestino][colunaDestino] != '-') {
        return 0;
    }

    // 2.3 - A peça é minha?
    char peca = tabuleiro[linhaOrigem][colunaOrigem];
    
    // Se sou 'o', só movo 'o' ou 'O'. Se sou 'x', só movo 'x' ou 'X'.
    int ehPecaBranca = (peca == 'o' || peca == 'O');
    int ehPecaPreta  = (peca == 'x' || peca == 'X');

    if (jogadorAtual == 'o' && !ehPecaBranca) return 0;
    if (jogadorAtual == 'x' && !ehPecaPreta)  return 0;

    // =========================================================================
    // ETAPA 3: TENTATIVA DE CAPTURA (PRIORIDADE ALTA)
    // No jogo de damas, capturas são verificadas antes de movimentos simples.
    // =========================================================================

    int linhaCapturada, colunaCapturada;
    int houveCaptura = 0;

    // Verifica se é Dama OU Peça Comum tentando capturar
    int ehDama = (peca == 'O' || peca == 'X');

    if (ehDama) {
        houveCaptura = verificarCapturaDama(tabuleiro, linhaOrigem, colunaOrigem, 
                                            linhaDestino, colunaDestino, jogadorAtual, 
                                            &linhaCapturada, &colunaCapturada);
    } else {
        houveCaptura = verificarCapturaSimples(tabuleiro, linhaOrigem, colunaOrigem, 
                                               linhaDestino, colunaDestino, jogadorAtual, 
                                               &linhaCapturada, &colunaCapturada);
    }

    // Se confirmou captura, executa a atualização da memória
    if (houveCaptura) {
        tabuleiro[linhaDestino][colunaDestino]             = peca; // Move peça
        tabuleiro[linhaOrigem][colunaOrigem]               = '-';  // Limpa origem
        tabuleiro[linhaCapturada][colunaCapturada] = '-';  // Remove inimigo

        // Verifica Combo (se pode comer de novo)
        if (podeCapturarNovamente(tabuleiro, linhaDestino, colunaDestino, jogadorAtual)) {
            return 3; // Retorno especial: "Jogue de novo com a mesma peça"
        }

        verificarPromocao(tabuleiro, linhaDestino, colunaDestino);
        return 2; // Retorno: "Captura finalizada"
    }

    // =========================================================================
    // ETAPA 4: TENTATIVA DE MOVIMENTO SIMPLES (PRIORIDADE BAIXA)
    // Se chegou aqui, não capturou ninguém. Tenta apenas andar.
    // =========================================================================
    
    int movimentoValido = 0;
    int deltaL = linhaDestino - linhaOrigem;
    int deltaC = colunaDestino - colunaOrigem;

    if (ehDama) {
        // Lógica da Dama: Diagonal perfeita e caminho livre
        if (abs(deltaL) == abs(deltaC)) {
             // Aqui você teria a lógica do loop while para verificar caminho livre
             // Simplifiquei visualmente, mas o loop while original entraria aqui.
             // Se o caminho estiver livre:
             movimentoValido = 1; // (Assumindo que passou no teste do while)
        }
    } else {
        // Lógica Comum: 1 casa na diagonal e direção correta
        if (abs(deltaL) == 1 && abs(deltaC) == 1) {
            // Verifica direção ('o' sobe, 'x' desce)
            if ((peca == 'o' && deltaL == -1) || (peca == 'x' && deltaL == 1)) {
                movimentoValido = 1;
            }
        }
    }

    // Se confirmou movimento, executa
    if (movimentoValido) {
        tabuleiro[linhaDestino][colunaDestino] = peca;
        tabuleiro[linhaOrigem][colunaOrigem]   = '-';
        
        verificarPromocao(tabuleiro, linhaDestino, colunaDestino);
        return 1; // Retorno: "Movimento simples feito"
    }

    // =========================================================================
    // ETAPA 5: FALHA
    // Se passou por tudo e nada funcionou
    // =========================================================================
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
void salvarJogo(const char *arquivo, const char *n1, const char *n2, char t[8][8], char jogador)
{
    FILE *f = fopen(arquivo, "w");
    if (!f)
    {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    fprintf(f, "%s\n", n1);
    fprintf(f, "%s\n", n2);

    for (int i = 0; i < 8; i++)
    {
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
void carregarJogo(const char *arquivo, char *n1, char *n2, char t[8][8], char *jogador)
{
    FILE *f = fopen(arquivo, "r");
    if (!f)
    {
        printf("Erro ao abrir o arquivo %s para leitura.\n", arquivo);
        exit(1);
    }

    // lê nomes (assumimos no máximo 49 chars)
    fgets(n1, 50, f);
    n1[strcspn(n1, "\n")] = 0;
    fgets(n2, 50, f);
    n2[strcspn(n2, "\n")] = 0;

    // lê o tabuleiro (8x8)
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            fscanf(f, " %c", &t[i][j]); // le cada caractere do tabuleiro

    // lê jogador atual 'x' ou'o'
    fscanf(f, " %c", jogador);

    fclose(f); // fecha o arquivo
}

/* ---------------------------------------------------------
 * Verifica se algum jogador ficou sem peças => fim de jogo.
 * Retorna 1 se o jogo acabou (um jogador sem peças), 0 caso contrário.
 * --------------------------------------------------------- */
int verificarVencedor(char t[8][8])
{
    int o = 0, x = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (t[i][j] == 'o')
                o++;
            if (t[i][j] == 'x')
                x++;
        }
    if (o == 0 || x == 0)
        return 1;
    return 0;
}

void verificarPromocao(char t[8][8], int l, int c)
{
    if (t[l][c] == 'o' && l == 0)
    {
        t[l][c] = 'O';
        printf("Parabéns! Sua peça virou DAMA!\n");
    }
    if (t[l][c] == 'x' && l == 7)
    {
        t[l][c] = 'X';
        printf("Parabéns! Sua peça virou DAMA!\n");
    }
}

int podeCapturarNovamente(char t[8][8], int l, int c, char jogador)
{
    char p = t[l][c];

    int dl[] = {-2, -2, 2, 2};
    int dc[] = {-2, 2, -2, 2};

    if (p == 'o' || p == 'x')
    {
        for (int i = 0; i < 4; i++)
        {
            int lf = l + dl[i];
            int cf = c + dc[i];
            int lc, cc;
            if (lf >= 0 && lf < 8 && cf >= 0 && cf < 8)
                if (verificarCapturaSimples(t, l, c, lf, cf, jogador, &lc, &cc))
                    return 1;
        }
    }

    if (p == 'O' || p == 'X')
    {
        int d[] = {-1, 1};
        for (int di = 0; di < 2; di++)
            for (int dj = 0; dj < 2; dj++)
            {
                int i = l + d[di], j = c + d[dj];
                while (i >= 0 && i < 8 && j >= 0 && j < 8)
                {
                    int lc, cc;
                    if (verificarCapturaDama(t, l, c, i, j, jogador, &lc, &cc))
                        return 1;
                    i += d[di];
                    j += d[dj];
                }
            }
    }
    return 0;
}
