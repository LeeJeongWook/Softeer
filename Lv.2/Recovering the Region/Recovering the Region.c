#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 50

int main(){
    int N;
    int sudoku[MAX][MAX];

    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &sudoku[i][j]);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}