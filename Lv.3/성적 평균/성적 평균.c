#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int N, K, A, B;
    float avg, sum;
    int score[1000000];

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++){
        scanf("%d", &score[i]);
    }

    for(int i = 0; i < K; i++){
        scanf("%d %d", &A, &B);
        sum = 0;
        for(int j = A - 1; j < B; j++){
            sum += score[j];
        }
        avg = sum / ((B + 1) - A);
        printf("%.02f\n", avg);
    }

    return 0;
}