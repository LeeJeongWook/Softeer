#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int N, len, idx = 0;

    scanf("%d", &N);

    char **S = malloc(N * sizeof(char *));
    char **T = malloc(N * sizeof(char *));
    
    char *ans = malloc(N * 100 * sizeof(char));

    for (int i = 0; i < N; i++) {
        char tempS[1000000];
        char tempT[1000000];

        scanf("%s %s", tempS, tempT);

        len = strlen(tempS);
        S[i] = malloc((len + 1) * sizeof(char));
        T[i] = malloc((len + 1) * sizeof(char));

        strcpy(S[i], tempS);
        strcpy(T[i], tempT);
    }

    for (int i = 0; i < N; i++) {
        len = strlen(S[i]);
        for (int j = 0; j < len; j++) {
            if (S[i][j] == 'x' || S[i][j] == 'X') {
                ans[idx++] = toupper(T[i][j]);
            }
        }
    }

    ans[idx] = '\0';

    printf("%s\n", ans);

    // 동적 메모리 해제
    for (int i = 0; i < N; i++) {
        free(S[i]);
        free(T[i]);
    }
    free(S);
    free(T);
    free(ans);

    return 0;
}