#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int T, A = 0, B = 0, sum;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A+B);
    }

    return 0;
}