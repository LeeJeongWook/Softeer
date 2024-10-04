#include <stdio.h>

int main(void){
    int N;

    scanf("%d", &N);
    /* 보드의 숫자들은 이미 N * N으로 출력할 경우 출력 형식을 만족함 */
    /* 1. N * N으로 정렬해서 출력 */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%d ", i + 1);
        printf("\n");
    }
    
    return 0;
}