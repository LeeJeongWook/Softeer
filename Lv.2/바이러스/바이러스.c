#include <stdio.h>

int main(void){
    int K, P, N;
    long long virus = 0;

    scanf("%d %d %d", &K, &P, &N);

    virus = K;

    for(int i = 0; i < N; i++)
        virus = (virus * P) % 1000000007;

    printf("%lld", virus);
    
    return 0;
}