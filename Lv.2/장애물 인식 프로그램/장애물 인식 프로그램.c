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

/* Func: ��� ȣ���� ���� DFS */
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
    /* Input: ������ ũ��(N), �� N���� �ڷ�(0 or 1) */
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &field[i][j]);
        }
    }
    
    /* 1. field Ž�� */
    area_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            count = 0;
            /* 1.1. �湮���� ���� ������ ��ֹ� �߽߰� count���� �� �ֺ� Ž�� */
            if((field[i][j] == 1) && (checked[i][j] == 0)){
                area_count++;
                /* 1.2. ��� ȣ���� ���� DFS */
                DFS(i, j);
            }
            /* 1.3. ������ ��ֹ� ũ�� �Է� */
            if(count) count_arr[idx++] = count;
        }
    }

    /* 2. ��ֹ� ũ�� �迭 ������������ ���� */
    printf("%d\n", area_count);
    qsort(count_arr, area_count, sizeof(int), compare);
    
    /* Output: �� ��ϼ�, �� ��� �� ��ֹ��� �� */
    for(int i = 0; i < area_count; i++){
        printf("%d\n", count_arr[i]);
    }
    
    return 0;
}