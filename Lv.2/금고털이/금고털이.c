#include <stdio.h>
#include <stdlib.h>

typedef struct _Stone{
    int weight;
    int price;
}stone;

int compare(const void *a, const void *b){
    stone* int_a = (const stone*)a;
    stone* int_b = (const stone*)b;

    if(int_a->price < int_b->price)
        return 1;
    else if(int_a->price > int_b->price)
        return -1;
    else
        return 0;
}

int main(void){
    int N, W, cost = 0;
    stone stone_arr[1000000];

    scanf("%d %d", &W, &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &stone_arr[i].weight, &stone_arr[i].price);
    }
    
    qsort(stone_arr, N, sizeof(stone), compare);

    for(int i = 0; i < N; i++){
        if(W - stone_arr[i].weight >= 0){
            W -= stone_arr[i].weight;
            cost += stone_arr[i].weight * stone_arr[i].price;
        }
        else{
            cost += W * stone_arr[i].price;
            break;
        }
    }

    printf("%d", cost);
    
    return 0;
}