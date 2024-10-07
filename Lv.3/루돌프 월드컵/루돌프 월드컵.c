#include <stdio.h>

int score[4];
double F[4];
double rate[4][4][3];

void DFS(){
    
}

int main(){

    /* Input: 루돌프의 힘을 나타내는 F[4] */
    for(int i = 0; i < 4; i++)
        scanf("%lf", &F[i]);

    /* 1. 루돌프 간의 승률 계산 */
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            /* 1.1. 같은 루돌프일 경우엔 넘어감 */
            if(i == j) continue;
            /* 1.2. 승, 패, 무승부 승률 입력 */
            rate[i][j][0] = ((5.0 * F[i]) + (5.0 * F[j])) / (4 * F[i]);
            rate[i][j][1] = ((5.0 * F[i]) + (5.0 * F[j])) / (4 * F[j]);
            rate[i][j][2] = ((F[i] * 5.0) + (F[j] * 5.0)) / (F[i] + F[j]);
        }
    }
    
    return 0;
}