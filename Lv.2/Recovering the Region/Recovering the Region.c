#include <stdio.h>

int main(void){
    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", i + 1);
        }
        printf("\n");
    }
    
    return 0;
}