#include <stdio.h>

int N, K, ans = 0;
int checked[20000];
char line[20001];

void Pick(int idx){
    /* 2. 로봇기준 왼쪽 탐색(로봇과 가장 먼 곳 부터) */
    for(int i = idx - K; i < idx; i++){
        if(i >= 0 && checked[i] == 0 && line[i] == 'H'){
            checked[i] = 1;
            ans++;
            return;
        }
    }
    /* 3. 로봇기준 오른쪽 탐색(로봇과 가장 가까운 곳 부터) */
    for(int i = idx + 1; i <= idx + K; i++){
        if(i < N && checked[i] == 0 && line[i] == 'H'){
            checked[i] = 1;
            ans++;
            return;
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);

    scanf("%s", line);
    /* 1. P(로봇)일 경우 잡을 수 있는 부품 탐색 */
    for(int i = 0; i < N; i++){
        if(line[i] == 'P')
            Pick(i);
    }

    printf("%d", ans);
    return 0;
}