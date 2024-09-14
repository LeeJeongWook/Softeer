#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int N;
    int dot = 0;
    int weight = 1;
    int length = 2;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        length = length * 2 - 1;
    }

    for(int j = 0; j < length; j++){
        dot += weight;
        weight += 2;
    }

    printf("%d", dot);

    return 0;
}