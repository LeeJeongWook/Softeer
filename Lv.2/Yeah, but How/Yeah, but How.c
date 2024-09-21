#include <stdio.h>
#include <string.h>

int main(void){
    int len, idx = 0;
    char s[200000];
    char ans[500000];

    scanf("%s", s);

    len = strlen(s);
    ans[idx++] = s[0];
    for(int i = 1; i < len; i++){
        if(s[i-1] == '(' && s[i] == ')'){
            ans[idx++] = '1';
            ans[idx++] = ')';
        }
        else if(s[i-1] == ')' && s[i] == '('){
            ans[idx++] = '+';
            ans[idx++] = '(';
        }
        else{
            ans[idx++] = s[i];
        }
    }

    printf("%s", ans);
    
    return 0;
}