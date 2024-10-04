#include <stdio.h>
#include <string.h>

int main(void){
    int len, idx = 0;
    char s[200000];
    char ans[500000];

    scanf("%s", s);

    len = strlen(s);
    /* 1. 첫 문자 삽입 */
    ans[idx++] = s[0];
    /* 2. 괄호 문자열 수식으로 변환 */
    for(int i = 1; i < len; i++){
        /* 2.1. ()일 경우 (1)로 치환 */
        if(s[i-1] == '(' && s[i] == ')'){
            ans[idx++] = '1';
            ans[idx++] = ')';
        }
        /* 2.2. )(일 경우 )+(로 치환 */
        else if(s[i-1] == ')' && s[i] == '('){
            ans[idx++] = '+';
            ans[idx++] = '(';
        }
        /* 2.3. 해당 없을 경우 그냥 삽입 */
        else{
            ans[idx++] = s[i];
        }
    }

    printf("%s", ans);
    
    return 0;
}