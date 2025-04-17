#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define NAVIO 3  // Representação de uma parte do navio

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para validar se uma posição está dentro dos limites do tabuleiro
int posicaoValida(int i, int j) {
    return (i >= 0 && i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO);
}

// Função para posicionar um navio horizontal ou vertical
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char direcao) {
    if (direcao == 'H') {  // Horizontal
        for (int i = 0; i < tamanho; i++) {
            if (!posicaoValida(x, y + i) || tabuleiro[x][y + i] == NAVIO) {
                return 0;  // Retorna 0 se a posição for inválida ou já estiver ocupada
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x][y + i] = NAVIO;
        }
    } else if (direcao == 'V') {  // Vertical
        for (int i = 0; i < tamanho; i++) {
            if (!posicaoValida(x + i, y) || tabuleiro[x + i][y] == NAVIO) {
                return 0;  // Retorna 0 se a posição for inválida ou já estiver ocupada
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y] = NAVIO;
        }
    }
    return 1;  // Retorna 1 se o navio foi posicionado com sucesso
}

// Função para posicionar um navio diagonal
int posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char direcao) {
    if (direcao == 'D') {  // Diagonal principal (crescente)
        for (int i = 0; i < tamanho; i++) {
            if (!posicaoValida(x + i, y + i) || tabuleiro[x + i][y + i] == NAVIO) {
                return 0;
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y + i] = NAVIO;
        }
    } else if (direcao == 'A') {  // Diagonal anti-principal (decrescente)
        for (int i = 0; i < tamanho; i++) {
            if (!posicaoValida(x + i, y - i) || tabuleiro[x + i][y - i] == NAVIO) {
                return 0;
            }
        }
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y - i] = NAVIO;
        }
    }
    return 1;
}

int main() {
    // Inicializa o tabuleiro com 0s (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona os navios (dois navios de 3 posições)

    // Navio horizontal (3 posições)
    if (!posicionarNavio(tabuleiro, 2, 2, 3, 'H')) {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // Navio vertical (3 posições)
    if (!posicionarNavio(tabuleiro, 5, 5, 3, 'V')) {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Navio diagonal crescente (3 posições)
    if (!posicionarNavioDiagonal(tabuleiro, 1, 1, 3, 'D')) {
        printf("Erro ao posicionar navio diagonal (crescente).\n");
    }


    // Exibe o tabuleiro
    printf("Tabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

