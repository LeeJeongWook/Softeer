#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ROW 5

int ans_idx, idx, len, tmp;
char key[100];
char message[1000];
char message_pair[1000][2];
char crypto[5][5];
char check[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
char checked[25];
char ans[10000];

int FindIndex(char a, char b){
    int ai, aj, bi, bj;
    /* 6. crypto에서 좌표 탐색 */
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < ROW; j++){
            if(a == crypto[i][j])
                ai = i, aj = j;
            if(b == crypto[i][j])
                bi = i, bj = j;
        }
    }
    /* 7. 행, 열 조건에 따라 암호화 */
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
    scanf("%s", message);
    scanf("%s", key);

    idx = 0;
    len = strlen(key);

    /* 1. key에서 사용한 알파벳 확인 */
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

    /* 2. checked에 key에서 사용하지 않은 알파벳 채우기 */
    for(int i = 0; i < 25; i++){
        if(check[i] != '0')
            checked[idx++] = check[i];
    }

    /* 3. 5*5표로 변환 */
    idx = 0;
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < ROW; j++)
            crypto[i][j] = checked[idx++];

    /* 4. 두 글자씩 쌍으로 변환 */
    idx = 0;
    len = strlen(message);
    for(int i = 0; i < len; i++){
        if(message[i + 1] == '\0'){
            message_pair[idx][0] = message[i];
            message_pair[idx++][1] = 'X';
        }
        else if(message[i] == message[i + 1]){
            message_pair[idx][0] = message[i];
            if(message[i] == 'X')
                message_pair[idx++][1] = 'Q';
            else
                message_pair[idx++][1] = 'X';
        }
        else{
            message_pair[idx][0] = message[i++];
            message_pair[idx++][1] = message[i];
        }
    }

    /* 5. 쌍을 맞춘 문자를 암호화 */
    len = strlen(message_pair)/2;
    ans_idx = 0;
    for(int i = 0; i < len; i++)
        FindIndex(message_pair[i][0], message_pair[i][1]);

    printf("%s", ans);
    return 0;
}