#include <stdio.h>

#define L 10
#define C 10

int main () {

    // 0 = agua
    // 3 = navio

    int matriz[L][C] = {0};

    // navio 1 na linha 2 (horizontal)

    matriz [9][2] = 3;
    matriz [9][3] = 3;
    matriz [9][4] = 3;

    // navio 2 na coluna 7 (vertical)

    matriz [5][7] = 3;    
    matriz [6][7] = 3;    
    matriz [7][7] = 3;
    matriz [8][7] = 3;
    matriz [9][7] = 3;

    // navio 3 na diagonal 1 (diagonal principal) esquema tabuleiro[i][i]

    matriz [1][1] = 3;    
    matriz [2][2] = 3;    
    matriz [3][3] = 3;
    matriz [4][4] = 3;

    // navio 4 na diagonal 2 (diagonal secundária) esquema tabuleiro[i][9-i]

    matriz [1][9] = 3;    
    matriz [2][8] = 3;    
    matriz [3][7] = 3;

    printf ("Tabuleiro de Batalha Naval\n\n");

    for (int i = 0; i < 10; i++) {  // linhas
        for (int j = 0; j < 10; j++) {  // colunas
            printf("%d ", matriz[i][j]); 
        }
        printf("\n");  // quebra de linha ao final de cada execução do loop aninhado
    }

    return 0;
}