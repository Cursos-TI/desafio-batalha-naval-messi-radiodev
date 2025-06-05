#include <stdio.h>
#include <stdlib.h> // para abs

#define L 10
#define C 10
#define matrizEspecial 5

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int matrizTabuleiro[L][C], int habilidade[matrizEspecial][matrizEspecial], int origemLinha, int origemColuna, int especial) {
    int meio = matrizEspecial / 2;

    for (int i = 0; i < matrizEspecial; i++) {
        for (int j = 0; j < matrizEspecial; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - meio + i;
                int colTab = origemColuna - meio + j;

                if (linhaTab >= 0 && linhaTab < L && colTab >= 0 && colTab < C) {
                    matrizTabuleiro[linhaTab][colTab] = especial;
                }
            }
        }
    }
}

int main() {
    int agua = 0;
    int navio = 3;
    int especial = 5;

    // Formatos dos especiais
    int cone[matrizEspecial][matrizEspecial] = {0};
    int cruz[matrizEspecial][matrizEspecial] = {0};
    int octaedro[matrizEspecial][matrizEspecial] = {0};

    // Tabuleiro inicial só água
    int matriz[L][C] = {agua};

    // Formato do especial em cone
    for (int i = 0; i < matrizEspecial; i++) {
        int CL = matrizEspecial/2 - i;  // coluna inicial
        int CF = matrizEspecial/2 + i;  // coluna final

        if (CL < 0 || CF >= matrizEspecial) continue;

        for (int j = CL; j <= CF; j++) {
            cone[i][j] = 1; // área afetada
        }
    }

    // Formato do especial em cruz
    for (int i = 0; i < matrizEspecial; i++) {
        cruz[matrizEspecial/2][i] = 1;
        cruz[i][matrizEspecial/2] = 1;
    }

    // Formato do especial em octaedro
    for (int i = 0; i < matrizEspecial; i++) {
        int distancia = abs(matrizEspecial/2 - i);
        int CL = distancia;
        int CF = matrizEspecial - 1 - distancia;

        for (int j = CL; j <= CF; j++) {
            octaedro[i][j] = 1;
        }
    }

    // Posicionando navios

    // Navio 1 na linha 9 (horizontal)
    matriz[9][2] = navio;
    matriz[9][3] = navio;
    matriz[9][4] = navio;

    // Navio 2 na coluna 7 (vertical)
    matriz[5][7] = navio;
    matriz[6][7] = navio;
    matriz[7][7] = navio;
    matriz[8][7] = navio;
    matriz[9][7] = navio;

    // Navio 3 na diagonal principal
    matriz[1][1] = navio;
    matriz[2][2] = navio;
    matriz[3][3] = navio;
    matriz[4][4] = navio;

    // Navio 4 na diagonal secundária
    matriz[1][9] = navio;
    matriz[2][8] = navio;
    matriz[3][7] = navio;

    // Mostrar tabuleiro antes
    printf("Tabuleiro inicial (0 = água, 3 = navio):\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Aplicar habilidades em diferentes posições
    aplicarHabilidade(matriz, cone, 2, 3, especial);     // Cone na posição (2,3)
    aplicarHabilidade(matriz, cruz, 6, 7, especial);     // Cruz na posição (6,7)
    aplicarHabilidade(matriz, octaedro, 8, 4, especial); // Octaedro na posição (8,4)

    // Mostrar tabuleiro depois
    printf("Tabuleiro após aplicar habilidades (5 = área afetada):\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
