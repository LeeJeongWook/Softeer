#include <stdio.h>

int score[4];
double F[4];
double rate[4][4][3];

void DFS(){
    
}

int main(){

    /* Input: �絹���� ���� ��Ÿ���� F[4] */
    for(int i = 0; i < 4; i++)
        scanf("%lf", &F[i]);

    /* 1. �絹�� ���� �·� ��� */
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            /* 1.1. ���� �絹���� ��쿣 �Ѿ */
            if(i == j) continue;
            /* 1.2. ��, ��, ���º� �·� �Է� */
            rate[i][j][0] = ((5.0 * F[i]) + (5.0 * F[j])) / (4 * F[i]);
            rate[i][j][1] = ((5.0 * F[i]) + (5.0 * F[j])) / (4 * F[j]);
            rate[i][j][2] = ((F[i] * 5.0) + (F[j] * 5.0)) / (F[i] + F[j]);
        }
    }
    
    return 0;
}