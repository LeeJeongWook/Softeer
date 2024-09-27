#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ROW 5

int idx, len, tmp;
char key[100];
char message[1000];
char message_pair[500][2];
char crypto[5][5];
char check[25] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char checked[25];

int FindIndex(char a, char b){
    int ai, aj, bi, bj;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < ROW; j++){
            if(a == crypto[i][j]){
                ai = i;
                aj = j;
            }
            if(b == crypto[i][j]){
                bi = i;
                bj = j;
            }
        }
    }

    printf("ai: %d, aj: %d\n", ai, aj);
    printf("bi: %d, bj: %d\n\n", bi, bj);

    return 0;
}

int main(){
    /* 1. message, key ���ڿ� �Է� */
    scanf("%s", message);
    scanf("%s", key);

    idx = 0;
    len = strlen(key);

    /* 2. key�� �� ���ھ� ���鼭 checked�� ä��� */
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

    /* 2. ���� �������� ���� ���ĺ� Count */
    len = sizeof(check);

    /* 3. checked�� ���� �������� ���� ���ĺ� ä���ֱ� */
    for(int i = 0; i < len; i++){
        if(check[i] != '0')
            checked[idx++] = check[i];
    }

    idx = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < ROW; j++){
            crypto[i][j] = checked[idx++];
        }
    }
    // crypto Ȯ��
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < ROW; j++){
            printf("%c ", crypto[i][j]);
        }
        printf("\n");
    }

    //Message 2���� ������
    idx = 0;
    len = strlen(message);
    for(int i = 0; i < len; i += 2){
        //printf("%c %c\n", message[i], message[i + 1]);
        message_pair[idx][0] = message[i];
        message_pair[idx++][1] = message[i + 1];
    }

    len = strlen(message)/2;
    for(int i = 0; i < len; i++){
        printf("msg pair: %c %c\n", message_pair[i][0], message_pair[i][1]);
    }

    for(int i = 0; i < len; i++){
        FindIndex(message_pair[i][0], message_pair[i][1]);
    }
    //1.���� ��
    //2.���� ��
    return 0;
}