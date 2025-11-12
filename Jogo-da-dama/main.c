/* damas.c
 *
 * Programa principal que usa as funções definidas em tabuleiro.c / tabuleiro.h.
 *
 * Fluxo:
 *  - Menu inicial: novo jogo ou continuar jogo salvo
 *  - Loop: cada jogador digita jogada "C3 D4" ou comando "salvar" / "sair"
 *  - Validações básicas: formato de entrada e execução via executarJogada
 *
 * Autor: SEU NOME
 * Matrícula: SEU NÚMERO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tabuleiro.h"

/* Função auxiliar: limpa buffer do teclado até o fim da linha.
 * Útil para garantir que fgets funcione corretamente.
 */
static void limparEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* Função auxiliar: normaliza entrada da casa (aceita minúsculas,
 * e garante que string tenha pelo menos 2 caracteres).
 * Retorna 1 se a string parece válida no formato "A1".."H8", 0 caso contrário.
 */
static int validarCasa(const char *s)
{
    if (!s)
        return 0;
    if (strlen(s) < 2)
        return 0;
    char letra = toupper((unsigned char)s[0]);
    char num = s[1];
    if (letra < 'A' || letra > 'H')
        return 0;
    if (num < '1' || num > '8')
        return 0;
    return 1;
}

int main()
{
    char opcao[10];
    char nome1[50] = "Jogador1";
    char nome2[50] = "Jogador2";
    char arquivo[100];
    char jogadorAtual = 'o'; // 'o' começa
    char tab[8][8];

    // layout inicial do jogo
    printf("=====================================\n");
    printf("      BEM-VINDO AO JOGO DE DAMAS\n");
    printf("=====================================\n\n");
    printf("1 - Novo jogo\n");
    printf("2 - Continuar jogo\n");
    printf("Escolha: ");

    if (scanf("%9s", opcao) != 1)
        return 0;

    limparEntrada();

    // se opção for igua a 2, de continuidade ao jogo salvo
    if (strcmp(opcao, "2") == 0)
    {
        printf("Digite o nome do arquivo: ");
        if (scanf("%99s", arquivo) != 1)
            return 0; // lê nome do arquivo
        limparEntrada();

        // carrega jogo salvo
        carregarJogo(arquivo, nome1, nome2, tab, &jogadorAtual);
    }
    else
    {
        // novo jogo: pede nomes e inicializa
        printf("Digite o nome do Jogador 1 (brancas - 'o'): ");
        fgets(nome1, sizeof(nome1), stdin);
        nome1[strcspn(nome1, "\n")] = 0; // remove \n

        printf("Digite o nome do Jogador 2 (pretas - 'x'): ");
        fgets(nome2, sizeof(nome2), stdin);
        nome2[strcspn(nome2, "\n")] = 0;

        inicializarTabuleiro(tab);
        jogadorAtual = 'o';
    }

    // imprime estado inicial
    imprimirTabuleiro(tab);

    // loop principal
    while (1)
    {
        char entrada[100];
        char origem[10], destino[10];

        // Mostra prompt com nome do jogador atual
        // se jogadorAtual for 'o', mostra nome1, senao nome2
        printf("%s  (%c), digite sua jogada (ex: C3 D4) ou 'salvar'/'sair': ",
               (jogadorAtual == 'o') ? nome1 : nome2, jogadorAtual);

        // lê a linha inteira (aceita espaços)
        if (!fgets(entrada, sizeof(entrada), stdin)) break;
        // remove \n final, se houver
        entrada[strcspn(entrada, "\n")] = 0;

        // ignora linhas vazias
        if (strlen(entrada) == 0) continue;

        // se o jogador digitou "sair"
        if (strcmp(entrada, "sair") == 0)
        {
            printf("Encerrando o jogo. Ate mais!\n");
            break;
        }

        // se digitou "salvar" sozinho
        if (strcmp(entrada, "salvar") == 0)
        {
            printf("Digite o nome do arquivo para salvar: ");
            if (scanf("%99s", arquivo) == 1)
            {
                limparEntrada();
                salvarJogo(arquivo, nome1, nome2, tab, jogadorAtual);
            }
            else
            {
                limparEntrada();
            }
            continue;
        }

        // tenta extrair duas "palavras" (origem e destino) da linha
        // sscanf retorna o número de itens lidos
        /*#include <stdio.h>

        int main() {
        char *s = "10 50";
        int idade, ano;
        sscanf(s, "%d %d", &idade, &ano); // Lê a string "10 50"

        printf("Idade: %d, Ano: %d\n", idade, ano);
        // Saída: Idade: 10, Ano: 50
        return 0;
        }
        */
        int n = sscanf(entrada, "%9s %9s", origem, destino);
        if (n != 2)
        {
            printf("Entrada invalida. Use o formato: C3 D4 ou comandos salvar/sair.\n");
            continue;
        }

        // valida formato das casas
        if (!validarCasa(origem) || !validarCasa(destino))
        {
            printf("Formato invalido. Linhas: A-H, colunas: 1-8 (ex: C3 D4).\n");
            continue;
        }

        // executa jogada chamando executarJogada (retorna 0/1/2)
        int res = executarJogada(tab, origem, destino, jogadorAtual);

        if (res == 0)
        {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        // imprimir sempre após movimento/captura
        imprimirTabuleiro(tab);

        if (res == 2)
        {
            // captura: jogador joga novamente
            printf("Captura realizada! Voce joga novamente.\n");
            // NÃO troca jogador
        }
        else
        {
            // movimento simples: troca jogador
            jogadorAtual = (jogadorAtual == 'o') ? 'x' : 'o';
        }

        // verifica fim de jogo
        if (verificarVencedor(tab))
        {
            // quem venceu? Se o jogador atual é 'o' e acabou agora,
            // o vencedor é o oposto (porque trocamos após movimento simples).
            // Para simplicidade: contamos as peças para descobrir vencedor.
            int contO = 0, contX = 0;
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (tab[i][j] == 'o')
                        contO++;
                    if (tab[i][j] == 'x')
                        contX++;
                }
            printf("=====================================\n");
            printf(" FIM DE JOGO!\n");
            if (contO == 0)
                printf(" Vencedor: %s\n", nome2); // pretas venceram
            else if (contX == 0)
                printf(" Vencedor: %s\n", nome1); // brancas venceram
            else
                printf(" Vencedor calculado: %s (caso especial)\n", (jogadorAtual == 'o') ? nome2 : nome1);
            printf("=====================================\n");
            break;
        }
    }

    return 0;
}
