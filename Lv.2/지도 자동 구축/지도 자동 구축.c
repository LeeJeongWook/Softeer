#include <stdio.h>

int main(void){
    int N;
    int T = 2;
    int W = -1;
    int dot = 0;
    
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        T = T * 2 - 1;

    for(int i = 0; i < T; i++){
        W = W + 2;
        dot += W;
    }

    printf("%d", dot);
    
    return 0;
}