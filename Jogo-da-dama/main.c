/* damas.c
 *
 * Programa principal do jogo de Damas.
 * Aqui fica o fluxo geral do jogo:
 *  - menu inicial
 *  - leitura de comandos do usuário
 *  - alternância de turnos
 *  - chamada das funções que implementam as regras
 *
 * Toda a lógica pesada do jogo (movimentos, capturas, dama)
 * está implementada em tabuleiro.c.
 *
 * Autor: SEU NOME
 * Matrícula: SEU NÚMERO
 */

#include <stdio.h>     // printf, scanf, fgets
#include <stdlib.h>    // funções gerais
#include <string.h>    // strlen, strcmp, strcspn
#include <ctype.h>     // toupper
#include "tabuleiro.h" // funções do tabuleiro

/* ---------------------------------------------------------
 * Função auxiliar para limpar o buffer do teclado.
 *
 * Problema comum em C:
 * - scanf deixa o '\n' no buffer
 * - o próximo fgets pode ler apenas esse '\n'
 *
 * Esta função descarta tudo até o final da linha.
 * --------------------------------------------------------- */
static void limparEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* ---------------------------------------------------------
 * Verifica se uma casa digitada pelo usuário é válida.
 * Formato esperado: "A1" até "H8".
 *
 * Retorna:
 *  1 -> formato válido
 *  0 -> formato inválido
 * --------------------------------------------------------- */
static int validarCasa(const char *s)
{
    // string vazia ou muito curta é inválida
    if (!s || strlen(s) < 2)
        return 0;

    // letra da linha (A..H)
    char l = toupper((unsigned char)s[0]);
    // número da coluna (1..8)
    char n = s[1];

    // verifica se está dentro do intervalo permitido
    return (l >= 'A' && l <= 'H' && n >= '1' && n <= '8');
}

/* ---------------------------------------------------------
 * Função principal do programa.
 * --------------------------------------------------------- */
int main()
{

    // matriz 8x8 que representa o tabuleiro
    char tab[8][8];

    // nomes dos jogadores
    char nome1[50], nome2[50];

    // nome do arquivo para salvar/carregar jogo
    char arquivo[100];

    // jogadorAtual:
    // 'o' -> jogador das peças brancas
    // 'x' -> jogador das peças pretas
    char jogadorAtual;

    // opção do menu inicial
    char opcao[10];

    /* ---------------- MENU INICIAL ---------------- */

    printf("=====================================\n");
    printf("      BEM-VINDO AO JOGO DE DAMAS\n");
    printf("=====================================\n");
    printf("1 - Novo jogo\n");
    printf("2 - Continuar jogo\n");
    printf("Escolha: ");

    // lê a opção escolhida
    scanf("%9s", opcao);
    limparEntrada();

    /* ---------------- NOVO JOGO OU JOGO SALVO ---------------- */

    if(strcmp(opcao, "1") == 0)
    {
        // opção de novo jogo
        printf("Digite o nome do Jogador 1 (brancas - 'o'): ");
        fgets(nome1, sizeof(nome1), stdin);//le o nome do jogador 1
        nome1[strcspn(nome1, "\n")] = 0; // remove '\n'

        printf("Digite o nome do Jogador 2 (pretas - 'x'): ");
        fgets(nome2, sizeof(nome2), stdin);//le o nome do jogador 2
        nome2[strcspn(nome2, "\n")] = 0;

        // inicializa o tabuleiro no estado padrão
        inicializarTabuleiro(tab);

        // jogador das brancas sempre começa
        jogadorAtual = 'o';
    }

    else if (strcmp(opcao, "2") == 0)
    {
        // opção de carregar jogo salvo
        printf("Digite o nome do arquivo: ");
        scanf("%99s", arquivo);
        limparEntrada();

        // carrega o jogo do arquivo
        carregarJogo(arquivo, nome1, nome2, tab, &jogadorAtual);
    }
    

    else{
        // --- CASO INVÁLIDO: DIGITOU QUALQUER OUTRA COISA ---
        printf("Opcao invalida! O programa sera encerrado.\n");
        
        // O "return 0" aqui mata a função main imediatamente.
        // O computador NUNCA vai chegar no while(1) lá embaixo.
        return 0;
        
    }
    
    // imprime o tabuleiro inicial
    imprimirTabuleiro(tab);

    /* ---------------- LOOP PRINCIPAL DO JOGO ---------------- */

    while (1)
    {
        char entrada[100]; // linha digitada pelo usuário
        char origem[10];   // casa de origem (ex: C3)
        char destino[10];  // casa de destino (ex: D4)

        // mostra de quem é a vez
        printf("%s (%c), digite sua jogada (ex: C3 D4) ou 'salvar'/'sair': ",
               (jogadorAtual == 'o') ? nome1 : nome2,
               jogadorAtual);

        // le a jogada feita por nome1 ou nome2
        // O jogo pausa e espera o usuário digitar qualquer coisa e dar ENTER.
        // Se fgets falhar (erro grave de sistema),
        // o break encerra o jogo imediatamente
        if (!fgets(entrada, sizeof(entrada), stdin))
            break;

        /*O Problema: Quando você digita "C3 D4" e dá Enter, o computador 
        recebe "C3 D4\n".A Solução: Essa linha procura onde está o \n 
        (o Enter) e o substitui por um 0 (que em C indica o fim da string).
         Agora a string é apenas "C3 D4".*/
        entrada[strcspn(entrada, "\n")] = 0;

        // ignora linha vazia
        if (strlen(entrada) == 0)
            continue;

        /* ---------------- COMANDOS ESPECIAIS ---------------- */

        // comando para sair do jogo
        //verifica se a entrada digita é "sair"
        if (strcmp(entrada, "sair") == 0)
        {
            printf("Encerrando o jogo. Ate mais!\n");
            break;
        }

        // comando para salvar o jogo
        //verifica se a entrada digita é "salvar"
        if (strcmp(entrada, "salvar") == 0)
        {
            printf("Digite o nome do arquivo para salvar: ");
            scanf("%99s", arquivo);
            limparEntrada();

            
            salvarJogo(arquivo, nome1, nome2, tab, jogadorAtual);

            /*Usa continue. Por quê? Porque se ele salvou, ele não fez
             um movimento de peça. O continue faz o loop voltar ao topo 
             imediatamente, pulando todo o resto do código abaixo.*/
            continue;
        }

        /* ---------------- LEITURA DA JOGADA ---------------- */

        // Tenta separar a entrada em duas palavras (ex: "C3" e "D4").
        // Se não encontrar exatamente duas palavras, considera erro.
        if (sscanf(entrada, "%9s %9s", origem, destino) != 2)
        {
            printf("Entrada invalida. Use: C3 D4\n");
            continue;//pula todo código abaixo e volta ao inicio
        }

        // valida formato das casas
        if (!validarCasa(origem) || !validarCasa(destino))
        {
            printf("Formato invalido. Use casas de A1 ate H8.\n");
            continue;
        }

        /* ---------------- EXECUÇÃO DA JOGADA ---------------- */

        // chama a função que executa a jogada
        // retorno:
        // 0 -> jogada inválida
        // 1 -> movimento simples
        // 2 -> captura finalizada
        // 3 -> captura múltipla continua
        int retornoDaExecucao = executarJogada(tab, origem, destino, jogadorAtual);

        if (retornoDaExecucao == 0)
        {
            printf("Jogada invalida!\n");
            continue;
        }

        // captura múltipla: mesmo jogador continua com a mesma peça
        if (retornoDaExecucao == 3)
        {
            printf("Captura realizada! Continue capturando com a MESMA peça.\n");
            continue;
        }

        // imprime o tabuleiro após a jogada
        imprimirTabuleiro(tab);

        // troca de jogador após movimento simples ou fim de captura
        if (retornoDaExecucao == 1 || retornoDaExecucao == 2)
        {
            jogadorAtual = (jogadorAtual == 'o') ? 'x' : 'o';
        }

        /* ---------------- VERIFICA FIM DE JOGO ---------------- */

        if (verificarVencedor(tab))
        {
            int contO = 0, contX = 0;

            // conta peças restantes no tabuleiro
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (tab[i][j] == 'o' || tab[i][j] == 'O')
                        contO++;
                    if (tab[i][j] == 'x' || tab[i][j] == 'X')
                        contX++;
                }

            printf("=====================================\n");
            printf(" FIM DE JOGO!\n");

            if (contO == 0)
                printf(" Vencedor: %s\n", nome2);
            else if (contX == 0)
                printf(" Vencedor: %s\n", nome1);
            else
                printf(" Jogo encerrado.\n");

            printf("=====================================\n");
            break;
        }
    }

    return 0;
}
