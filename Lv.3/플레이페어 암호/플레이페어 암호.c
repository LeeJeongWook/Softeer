#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ROW 5

int ans_idx, idx, len, tmp;
char key[100];
char message[1000];
char message_pair[1000][2];
char crypto[5][5];
char check[25] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char checked[25];
char ans[1000];

int FindIndex(char a, char b){
    int ai = -1, aj = -1, bi = -1, bj = -1;
    /*crypto에서 좌표 찾기*/
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
    // printf("%c ai: %d, aj: %d\n", a, ai, aj);
    // printf("%c bi: %d, bj: %d\n", b, bi, bj);
    if(ai == bi){
        aj = (aj == 4) ? 0 : aj + 1;
        bj = (bj == 4) ? 0 : bj + 1;
        ans[ans_idx++] = crypto[ai][aj];
        ans[ans_idx++] = crypto[bi][bj];
    }
    else if(aj == bj){
        ai = (ai == 4) ? 0 : ai + 1;
        bi = (bi == 4) ? 0 : bi + 1;
        ans[ans_idx++] = crypto[ai][aj];
        ans[ans_idx++] = crypto[bi][bj];
    }
    else{
        ans[ans_idx++] = crypto[ai][bj];
        ans[ans_idx++] = crypto[bi][aj];
    }
    return 0;
}

int main(){
    /* 1. message, key 문자열 입력 */
    scanf("%s", message);
    scanf("%s", key);

    idx = 0;
    len = strlen(key);

    //printf("%d, %d, %d, %d\n", 'A', 'Z', 'I', 'J');
    /* 2. key를 한 글자씩 보면서 checked를 채운다 */
    for(int i = 0; i < len; i++){
        if(key[i] > 74)
            tmp = key[i] - 66;
        else if(key[i] < 74)
            tmp = key[i] - 65;
        if(idx < 25 && check[tmp] != '0'){
            check[tmp] = '0';
            checked[idx++] = key[i];
        }
    }

    /* 3. checked에 아직 등장하지 않은 알파벳 채워넣기 */
    for(int i = 0; i < 25; i++){
        if(check[i] != '0')
            checked[idx++] = check[i];
    }

    idx = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < ROW; j++){
            crypto[i][j] = checked[idx++];
        }
    }
    // crypto 확인
    // for(int i = 0; i < ROW; i++){
    //     for(int j = 0; j < ROW; j++){
    //         printf("%c ", crypto[i][j]);
    //     }
    //     printf("\n");
    // }

    //Message 2개씩 나누기
    idx = 0;
    len = strlen(message);
    //printf("message: %s\n", message);
    for(int i = 0; i < len; i++){
        /*연속한 두 문자가 같을 경우*/
        if(message[i + 1] == '\0'){
            message_pair[idx][0] = message[i];
            message_pair[idx++][1] = 'X';
        }
        else if(message[i] == message[i + 1]){
            /*연속한 두 문자가 X일 경우*/
            message_pair[idx][0] = message[i];
            if(message[i] == 'X')
                message_pair[idx++][1] = 'Q';
            else
                message_pair[idx++][1] = 'X';
        }
        else{
            message_pair[idx][0] = message[i];
            message_pair[idx++][1] = message[++i];
        }
    }
    len = idx;
    /*문자열 자르기 확인*/
    // for(int i = 0; i < len; i++){
    //     printf("msg pair: %c %c\n", message_pair[i][0], message_pair[i][1]);
    // }
    ans_idx = 0;
    for(int i = 0; i < len; i++)
        FindIndex(message_pair[i][0], message_pair[i][1]);

    printf("%s", ans);
    return 0;
}