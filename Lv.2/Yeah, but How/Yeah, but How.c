#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <string.h>

char S[200000];
char T[500000];
int idx = 0;

void solution(){
    int len = strlen(S);
    T[idx++] = S[0];
    for(int i = 1; i < len; i++){
        if(S[i-1] == '(' && S[i] == ')'){
            T[idx++] = '1';
            T[idx++] = ')';
        }
        else if(S[i-1] == ')' && S[i] == '('){
            T[idx++] = '+';
            T[idx++] = '(';
        }
        else
            T[idx++] = S[i];
    }
    
    printf("%s", T);
}

int main(){
    scanf("%s", S);
    solution();
 
    return 0;
}