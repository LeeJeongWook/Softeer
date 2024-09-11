#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int land[3][3], a, b, c, tmp, cheapest = 6;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &land[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 1; j < 4; j++){
            tmp = abs(j - land[i][0]) + abs(j - land[i][1]) + abs(j - land[i][2]);
            if(tmp < cheapest)
                cheapest = tmp;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 1; j < 4; j++){
            tmp = abs(j - land[0][i]) + abs(j - land[1][i]) + abs(j - land[2][i]);
            if(tmp < cheapest)
                cheapest = tmp;
        }
    }

    printf("%d", cheapest);

    return 0;    
}