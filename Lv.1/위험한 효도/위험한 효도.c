#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a, b, d, t1 = 0, t2 = 0, d_cnt = 0;

    scanf("%d %d %d", &a, &b, &d);

    while(d_cnt <= d){
        t1 += a;
        d_cnt += a;
        if(d_cnt >= d){
            t1 -= (d_cnt - d);
            d_cnt -= (d_cnt - d);
            break;
        }
        t1 += b;
    }

    while(d_cnt > 0){
        t2 += b;
        d_cnt -= b;
        if(d_cnt <= 0){
            t2 += d_cnt;
            break;
        }
        t2 += a;
    }

    printf("%d", t1 + t2);

    return 0;
}