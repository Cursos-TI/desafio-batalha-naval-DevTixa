#include <stdio.h>

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    int i, j;
    int tamanhoNavio = 3;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // Coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 1; // Horizontal
    int linhaV = 5, colunaV = 7; // Vertical

    // Validação dos limites
    if (colunaH + tamanhoNavio > 10 || linhaV + tamanhoNavio > 10) {
        printf("Erro: navio fora dos limites!\n");
        return 1;
    }

    // Posiciona navio horizontal
    for (i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: sobreposição!\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Posiciona navio vertical
    for (i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: sobreposição!\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Exibe o tabuleiro
    printf("\n   ");
    for (j = 0; j < 10; j++) printf("%d ", j);
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%c: ", linha[i]);
        for (j = 0; j < 10; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}



    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


