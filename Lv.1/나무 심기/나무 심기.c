#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int n, ans = -10000;
    int T[100];

    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &T[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((T[i] * T[j]) > ans)
                ans = T[i] * T[j];
        }
    }

    printf("%d", ans);

    return 0;
}