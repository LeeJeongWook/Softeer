#include <stdio.h>

int N, K;
int checked[20000];
char line[20000];

void Pick(int idx){
    int cnt = K;
    for(int i = idx - K; i < idx; i++){
        if(checked[i] == 0 && line[i] == 'H'){
            checked[i] = 1;
            return;
        }
    }
    for(int i = idx + K; i > idx; i--){
        if(checked[i] == 0 && line[i] == 'H'){
            checked[i] = 1;
            return;
        }
    }
    // while(cnt){
    //     i++;
    //     if(checked[idx - i] = 0 && line[idx - i] == 'H'){
    //         checked[idx - i] = 1;
    //         break;
    //     }
    //     else if(checked[idx + i] = 0 && line[idx + i] == 'H'){
    //         checked[idx + i] = 1;
    //         break;
    //     }
    //     cnt--;
    // }
    return;
}

int main(){
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        scanf(" %c", &line[i]);
    
    for(int i = 0; i < N; i++){
        printf("line[%d]: %c\n",i, line[i]);
    }
    printf("\n\n");

    
    for(int i = 0; i < N; i++){
        printf("i: %d\n", i);
        if(line[i] == 'P'){
            checked[i] = 1;
            Pick(i);
        }
        printf("checked: ");
        for(int j = 0; j < N; j++){
            printf("%d", checked[j]);
        }
        printf("\n");
    }
    return 0;
}