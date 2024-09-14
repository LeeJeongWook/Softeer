#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_MAX 100

int K, M, N;
int secret[NUM_MAX];
int button[NUM_MAX];
int flag;

int main(){
    scanf("%d %d %d", &M, &N, &K);

    for(int i = 0; i < M; i++){
        scanf("%d", &secret[i]);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &button[i]);
    }

    for(int i = 0; i <= N - M; i++){
        flag = 1;
        for(int j = 0; j < M; j++){
            if(button[i + j] != secret[j]){
                flag = 0;
            }
        }
        if(flag)
            break;
    }

    if(flag)
        printf("secret");
    else
        printf("normal");

    return 0;
}