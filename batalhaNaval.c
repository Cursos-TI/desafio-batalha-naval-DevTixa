#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Valor que representa navio
#define AGUA 0        // Valor que representa água
#define EFEITO 5      // Valor que representa área de efeito
#define TAM_NAVIO 3   // Tamanho fixo de cada navio
#define HL 3          // Linhas das habilidades
#define HC 5          // Colunas das habilidades

// Inicializa o tabuleiro com água
void inicializar_tabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

// Exibe o tabuleiro no console
void exibir_tabuleiro(int tab[TAM][TAM], char linha[10]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    printf("   ");
    for (int j = 0; j < TAM; j++)
        printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c: ", linha[i]);
        for (int j = 0; j < TAM; j++) {
            int valor = tab[i][j];
            if (valor == AGUA) printf("0 ");
            else if (valor == NAVIO) printf("3 ");
            else if (valor == EFEITO) printf("5 ");
        }
        printf("\n");
    }
}

// ======== MATRIZES DE HABILIDADES ========

// Habilidade em forma de CONE (3x5)
void habilidade_cone(int m[HL][HC]) {
    for (int i = 0; i < HL; i++) {
        for (int j = 0; j < HC; j++) {
            if ((i == 0 && j == 2) || 
                (i == 1 && j >= 1 && j <= 3) || 
                (i == 2)) // linha inteira
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Habilidade em forma de CRUZ (3x5)
void habilidade_cruz(int m[HL][HC]) {
    for (int i = 0; i < HL; i++) {
        for (int j = 0; j < HC; j++) {
            if ((i == 1) || (j == 2))
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Habilidade em forma de OCTAEDRO (3x5)
void habilidade_octaedro(int m[HL][HC]) {
    for (int i = 0; i < HL; i++) {
        for (int j = 0; j < HC; j++) {
            if ((i == 0 && j == 2) || 
                (i == 1 && j >= 1 && j <= 3) || 
                (i == 2 && j == 2))
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Aplica a habilidade no tabuleiro
void aplicar_habilidade(int tab[TAM][TAM], int hab[HL][HC], int origem_l, int origem_c) {
    int inicio_l = origem_l - HL / 2;
    int inicio_c = origem_c - HC / 2;

    for (int i = 0; i < HL; i++) {
        for (int j = 0; j < HC; j++) {
            int pos_l = inicio_l + i;
            int pos_c = inicio_c + j;

            // Dentro dos limites
            if (pos_l >= 0 && pos_l < TAM && pos_c >= 0 && pos_c < TAM) {
                if (hab[i][j] == 1 && tab[pos_l][pos_c] == AGUA)
                    tab[pos_l][pos_c] = EFEITO;
            }
        }
    }
}

// ======== PROGRAMA PRINCIPAL ========

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[TAM][TAM];
    inicializar_tabuleiro(tabuleiro);

    // Coordenadas dos navios
    int linhaH = 1, colunaH = 1; 
    int linhaV = 5, colunaV = 7;
    int linhaD1 = 0, colunaD1 = 6; 
    int linhaD2 = 6, colunaD2 = 9; 

    // Posiciona os navios
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
        tabuleiro[linhaV + i][colunaV] = NAVIO;
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
    }

    // Cria as habilidades
    int cone[HL][HC], cruz[HL][HC], octaedro[HL][HC];
    habilidade_cone(cone);
    habilidade_cruz(cruz);
    habilidade_octaedro(octaedro);

    // Aplica as habilidades em posições diferentes
    aplicar_habilidade(tabuleiro, cone, 4, 4);
    aplicar_habilidade(tabuleiro, cruz, 8, 2);
    aplicar_habilidade(tabuleiro, octaedro, 2, 8);

    // Exibe o tabuleiro completo
    exibir_tabuleiro(tabuleiro, linha);

    return 0;
}

