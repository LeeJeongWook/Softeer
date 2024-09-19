#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

int N, pop = 0;
int Pi[MAX];
int Ci[MAX];

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &Pi[i], &Ci[i]);
    }

    for(int i = 0; i < N; i++){
        if(abs(pop - Pi[i]) <= Ci[i]){
            pop++;
        }
    }

    printf("%d", pop);

    return 0;
}