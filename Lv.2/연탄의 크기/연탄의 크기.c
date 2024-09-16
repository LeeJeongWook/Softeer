#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

int main(){
    int n, cnt, max = 0, max_cnt = 0;
    int house[MAX];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &house[i]);
        if(house[i] > max)
            max = house[i];
    }

    for(int i = 2; i <= max; i++){
        cnt = 0;
        for(int j = 0; j < n; j++){
            if(house[j] % i == 0)
                cnt++;
        }
        if(cnt > max_cnt)
            max_cnt = cnt;
    }

    printf("%d", max_cnt);

    return 0;
}