#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <string.h>

char S[200000];
char T[500000];
int idx = 0;

void solution(){
    for(int i = 0; i < (int)strlen(S); i++){
        if(S[i] == '('){
            if(S[i + 1] == '('){
                T[idx++] = '(';
                continue;
            }
            else if(i != 0 && S[i - 1] == ')'){
                T[idx++] = '+';
                T[idx++] = '(';
                T[idx++] = '1';
            }
            else{
                T[idx++] = '(';
                T[idx++] = '1';
            }
        }
        else if(S[i] == ')'){
            T[idx++] = ')';
        }
    }
    printf("%s", T);
}

int main(){
    scanf("%s", S);
    solution();
 
    return 0;
}