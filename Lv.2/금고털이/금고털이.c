#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int W, N, weight = 0, cost = 0;

struct data
{
    int M;
    int P;
};

struct data jewelry[MAX];

int compare(const void* a, const void* b){
    struct data* dataA = (struct data*)a;
    struct data* dataB = (struct data*)b;
    
    if(dataA->P < dataB->P)
        return 1;
    else if(dataA->P > dataB->P)
        return -1;
    else
        return 0;
}

int main(){
    scanf("%d %d", &W, &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &jewelry[i].M, &jewelry[i].P);
    }

    qsort(jewelry, N, sizeof(struct data), compare);

    for(int i = 0; i < N; i++){
        if(W >= jewelry[i].M){
            W -= jewelry[i].M;
            cost += jewelry[i].M * jewelry[i].P;
        }
        else{
            cost += W * jewelry[i].P;
            break;
        }
    }

    printf("%d", cost);

    return 0;
}