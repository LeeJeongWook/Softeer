#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 25

int N;
int map[SIZE_MAX][SIZE_MAX];
int visited[SIZE_MAX][SIZE_MAX];
int block_size[SIZE_MAX * SIZE_MAX];
int block_cnt = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DFS(int x, int y, int block_num){
    visited[x][y] = 1;
    block_size[block_num]++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
            if(map[nx][ny] == 1 && visited[nx][ny] == 0){
                DFS(nx, ny, block_num);
            }
        }
    }
}

int Compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                DFS(i, j, block_cnt);
                block_cnt++;
            }
        }
    }

    qsort(block_size, block_cnt, sizeof(int), Compare);

    printf("%d\n", block_cnt);
    for(int i = 0; i < block_cnt; i++){
        printf("%d\n", block_size[i]);
    }

    return 0;
}