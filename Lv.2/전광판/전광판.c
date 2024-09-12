#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(){
    int T, A, B, idx_1, idx_2, cnt;

    int number[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},  // 0老锭 菊磊府老锭客 抗寇贸府
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
    };

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %d", &A, &B);
        cnt = 0;
        for(int j = 0; j < 5; j++){
            idx_1 = A % 10;
            idx_2 = B % 10;
            printf("A: %d\n", idx_1);
            printf("B: %d\n", idx_2);
            for(int k = 0; k < 7; k++){
                if(number[idx_1][k] != number[idx_2][k])
                    cnt++;
            }
            printf("cnt: %d\n", cnt);
            A /= 10;
            B /= 10;
        }
        printf("%d\n", cnt);
    }

}