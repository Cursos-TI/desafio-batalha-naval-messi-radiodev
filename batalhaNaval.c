#include <stdio.h>

int main () {

    // 0 = agua
    // 3 = navio

    int matriz[10][10] = {0};

    // navio 1 na linha 2 (horizontal)

    matriz [2][2] = 3;
    matriz [2][3] = 3;
    matriz [2][4] = 3;

    // navio 2 na coluna 7 (vertical)

    matriz [5][7] = 3;    
    matriz [6][7] = 3;    
    matriz [7][7] = 3;
    matriz [8][7] = 3;
    matriz [9][7] = 3;

    printf ("Tabuleiro de Batalha Naval\n\n");

    for (int i = 0; i < 10; i++) {  // linhas
        for (int j = 0; j < 10; j++) {  // colunas
            printf("%d ", matriz[i][j]); 
        }
        printf("\n");  // quebra de linha ao final de cada execução do loop aninhado
    }

    return 0;
}