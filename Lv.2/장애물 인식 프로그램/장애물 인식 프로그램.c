#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int N, area_count, count, idx = 0;
int count_arr[MAX*MAX];
int field[MAX][MAX];
int checked[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

/* Func: 재귀 호출을 통한 DFS */
void DFS(int x, int y){
    count++;
    checked[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((0 <= nx) && (nx < N) && (0 <= ny) && (ny < N)){
            if((field[nx][ny] == 1) && (checked[nx][ny] == 0)){
                DFS(nx, ny);
            }
        }
    }
    return;
}

int main(void){
    /* Input: 지도의 크기(N), 각 N개의 자료(0 or 1) */
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &field[i][j]);
        }
    }
    
    /* 1. field 탐색 */
    area_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            count = 0;
            /* 1.1. 방문하지 않은 영역의 장애물 발견시 count증가 및 주변 탐색 */
            if((field[i][j] == 1) && (checked[i][j] == 0)){
                area_count++;
                /* 1.2. 재귀 호출을 통한 DFS */
                DFS(i, j);
            }
            /* 1.3. 영역의 장애물 크기 입력 */
            if(count) count_arr[idx++] = count;
        }
    }

    /* 2. 장애물 크기 배열 오름차순으로 정렬 */
    printf("%d\n", area_count);
    qsort(count_arr, area_count, sizeof(int), compare);
    
    /* Output: 총 블록수, 각 블록 내 장애물의 수 */
    for(int i = 0; i < area_count; i++){
        printf("%d\n", count_arr[i]);
    }
    
    return 0;
}