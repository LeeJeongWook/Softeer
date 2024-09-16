#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MOD 1000000007

int main(){
    int K, P, N;
    long long virus;

    scanf("%d %d %d", &K, &P, &N);

    virus = K;

    for(int i = 0; i < N; i++){
        virus = (virus * P) % MOD;
    }

    printf("%lld", virus);

    return 0;
}