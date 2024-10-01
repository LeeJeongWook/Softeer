#include <stdio.h>

int N, K, ans = 0;
int checked[20000];
char line[20001];

void Pick(int idx){
    for(int i = idx - K; i < idx; i++){
        if(i >= 0 && checked[i] == 0 && line[i] == 'H'){
            checked[i] = 1;
            ans++;
            return;
        }
    }
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
    
    for(int i = 0; i < N; i++){
        if(line[i] == 'P')
            Pick(i);
    }

    printf("%d", ans);
    return 0;
}