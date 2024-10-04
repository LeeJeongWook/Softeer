#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 500000

char S[MAX];
char T[MAX];

int main(void) {
    int N, len, idx = 0;
    char ans[MAX];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s %s", S, T);

        len = strlen(S);
        for (int j = 0; j < len + 1; j++) {
            if (S[j] == 'x' || S[j] == 'X')
                ans[idx++] = toupper(T[j]);
        }
    }
    
    printf("%s\n", ans);

    return 0;
}