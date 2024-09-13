#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(){
    int T, A, B, idx_1, idx_2, cnt;

    int number[11][7] = {
        {1, 1, 1, 0, 1, 1, 1},  //0
        {0, 0, 1, 0, 0, 1, 0},  //1
        {1, 0, 1, 1, 1, 0, 1},  //2
        {1, 0, 1, 1, 0, 1, 1},  //3
        {0, 1, 1, 1, 0, 1, 0},  //4
        {1, 1, 0, 1, 0, 1, 1},  //5
        {1, 1, 0, 1, 1, 1, 1},  //6
        {1, 1, 1, 0, 0, 1, 0},  //7
        {1, 1, 1, 1, 1, 1, 1},  //8
        {1, 1, 1, 1, 0, 1, 1},  //9
        {0, 0, 0, 0, 0, 0, 0}   //' '
    };

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %d", &A, &B);
        cnt = 0;
        for(int j = 0; j < 5; j++){
            if(A == 0)
                idx_1 = 10;
            else
                idx_1 = A % 10;
            if(B == 0)
                idx_2 = 10;
            else
                idx_2 = B % 10;

            int tmp_cnt = 0;
            for(int k = 0; k < 7; k++){
                if(number[idx_1][k] != number[idx_2][k]){
                    tmp_cnt++;
                    cnt++;
                }
            }
            A /= 10;
            B /= 10;
        }
        printf("%d\n", cnt);
    }

}