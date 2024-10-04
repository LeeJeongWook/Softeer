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
        /* 1. S(T)�� ���̸�ŭ x(X) Ž�� */
        for (int j = 0; j < len; j++) {
            /* 1.1. S���� x(X)�� �����ϴ� ��ġ�� ��ġ�Ǵ� T�� ���ڸ� �빮�ڷ� ��ȯ */
            if (S[j] == 'x' || S[j] == 'X')
                    ans[idx++] = toupper(T[j]);
        }
    }
    
    printf("%s\n", ans);

    return 0;
}