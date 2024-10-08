#include <stdio.h>

#define MAX 100000

int N;
int rate[MAX];
int final_rate[MAX];

int main(){
    scanf("%d", &N);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; i++){
            scanf("%d", &rate[i]);
        }
    }

    return 0;
}