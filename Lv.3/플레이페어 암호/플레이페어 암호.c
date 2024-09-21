#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int idx, len, tmp;
char key[100];
char message[1000];
char crypto[5][5];
char check[25] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char checked[25];

int main(){
    scanf("%s", message);
    scanf("%s", key);

    idx = 0;
    len = strlen(key);

    for(int i = 0; i < len; i++){
        if(key[i] > 74)
            tmp = key[i] - 66;
        else
            tmp = key[i] - 65;
        if(check[tmp] != '0'){
            check[tmp] = '0';
            checked[idx++] = key[i];
        }
    }

    len = sizeof(check);
    for(int i = 0; i < len; i++){
        if(check[i] != '0')
            checked[idx++] = check[i];
    }

    idx = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            crypto[i][j] = checked[idx++];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%c ", crypto[i][j]);
        }
        printf("\n");
    }

    return 0;
}