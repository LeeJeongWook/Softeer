#define _CRT_SRCURE_NO_WARNINGS
#include <stdio.h>

int n, max, nx, ny, max_val = 0;
int forest[4][4];
int visited[4][4] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void Search(int i, int j){
    if(visited[i][j] == 0){
        max = 0;
        for(int k = 0; k < 4; k++){
            nx = j + dx[k];
            ny = i + dy[k];
            if((nx >= 0 && nx < n && ny >= 0 && ny < n) && (max < forest[i][j] + forest[ny][nx]))
                max = forest[i][j] + forest[ny][nx];
        }
        visited[i][j] = max;
        if(max > max_val)
            max_val = max;
        //printf("visited[%d][%d] max: %d\n", i, j, max);
    }
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &forest[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Search(i, j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Search(i, j);
        }
    }

    printf("max_val: %d\n", max_val);
    printf("\n\n======================\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }

    return 0;
}