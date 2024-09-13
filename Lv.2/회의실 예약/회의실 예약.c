#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_NAME_MAX 10
#define TIME_TABLE 10

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(){
    char flag = 0;
    int N, M, s, t, idx, cnt;
    char r[11];
    
    scanf("%d %d", &N, &M);
    
    char **room = malloc(N * sizeof(char *));   //회의실 이름

    for(int i = 0; i < N; i++){
        room[i] = malloc(ROOM_NAME_MAX * sizeof(char));
        scanf("%s", room[i]);
    }

    qsort(room, N, sizeof(char *), compare);

    int **time = malloc(N * sizeof(int *));     //회의실 Time Table

    for (int i = 0; i < N; i++) {
        time[i] = malloc(TIME_TABLE * sizeof(int));
        memset(time[i], 0, TIME_TABLE * sizeof(int));
    }

    for(int i = 0; i < M; i++){     //회의실 사용시간 M번 입력
        scanf("%10s %d %d", r, &s, &t);
        
        for(int j = 0; j < N; j++){
            if(strcmp(room[j], r) == 0){
                idx = j;
                break;
            }
        }
        if(t == 18)
            time[idx][9] = 1;
        for(int k = s - 9; k < t - 9; k++){
            time[idx][k] = 1;
        }
    }

    for(int i = 0; i < N; i++){
        flag = 0;
        cnt = 0;
        printf("Room %s:\n", room[i]);
        for(int j = 0; j < TIME_TABLE; j++){
            if(!flag && time[i][j] == 0){
                flag = 1;
            }
            else if(flag && time[i][j] == 1){
                cnt++;
                flag = 0;
            }
            else if(flag && j == 9){
                cnt++;
            }
        }
        
        if(cnt == 0){
            printf("Not available\n");
        }
        else{
            printf("%d available:\n", cnt);
            flag = 0;
            for(int j = 0; j < TIME_TABLE; j++){
                if(!flag && time[i][j] == 0){
                    printf("%02d", j + 9);
                    flag = 1;
                }
                else if((flag && time[i][j] == 1) || (flag && j == 9)){
                    if(flag){
                        printf("-%02d\n", j + 9);
                        flag = 0;
                    }
                }
            }           
        }
        if(i == N-1){
            break;
        }
        printf("-----\n");
    }

    free(room);
    free(time);

    return 0;
}