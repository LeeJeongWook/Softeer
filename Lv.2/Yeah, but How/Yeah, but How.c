#include <stdio.h>
#include <string.h>

int main(void){
    int len, idx = 0;
    char s[200000];
    char ans[500000];

    scanf("%s", s);

    len = strlen(s);
    /* 1. ù ���� ���� */
    ans[idx++] = s[0];
    /* 2. ��ȣ ���ڿ� �������� ��ȯ */
    for(int i = 1; i < len; i++){
        /* 2.1. ()�� ��� (1)�� ġȯ */
        if(s[i-1] == '(' && s[i] == ')'){
            ans[idx++] = '1';
            ans[idx++] = ')';
        }
        /* 2.2. )(�� ��� )+(�� ġȯ */
        else if(s[i-1] == ')' && s[i] == '('){
            ans[idx++] = '+';
            ans[idx++] = '(';
        }
        /* 2.3. �ش� ���� ��� �׳� ���� */
        else{
            ans[idx++] = s[i];
        }
    }

    printf("%s", ans);
    
    return 0;
}