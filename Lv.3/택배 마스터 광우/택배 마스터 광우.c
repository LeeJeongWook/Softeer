#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int N, M, K;
int line[50];
int min = INT_MAX;

void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Permute(int *arr, int l, int r){
    if(l == r){
        int count = 0;
        int weight = 0;
        int total_weight = 0;
        int index = 0;

        while(1){
            if(count == K){
                index = 0;                break;
            }

            if(weight + arr[index] <= M){
                weight += arr[index];
                total_weight += arr[index];
                index++;
            }
            else{
                count++;
                weight = 0;
            }
            if(index == N)
                index = 0;
        }
        if(min > total_weight)
            min = total_weight;
    }
    else{
        for(int i = l; i <= r; i++){
            Swap((arr + l), (arr + i));
            Permute(arr, l + 1, r);
            Swap((arr + l), (arr + i));
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);

    for(int i = 0; i < N; i++){
        scanf("%d", &line[i]);
    }

    Permute(line, 0, N-1);

    printf("%d\n", min);
    return 0;
}

