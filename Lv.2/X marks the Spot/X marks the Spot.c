#include <stdio.h>
#include <string.h>

#define MAX 1000000

char S[MAX];
char T[MAX];
char ans[MAX];

int main(void) {
    int N, len, idx = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s %s", S, T);
        len = strlen(S);
        /* 1. S(T)의 길이만큼 x(X) 탐색 */
        for (int j = 0; j < len; j++) {
            /* 1.1. S에서 x(X)가 등장하는 위치와 대치되는 T의 문자를 대문자로 변환 */
            if (S[j] == 'x' || S[j] == 'X')
                    ans[idx++] = toupper(T[j]);
        }
    }
    
    printf("%s\n", ans);

    return 0;
}