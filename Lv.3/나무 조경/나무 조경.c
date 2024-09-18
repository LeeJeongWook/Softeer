#define _CRT_SRCURE_NO_WARNINGS
#include <stdio.h>

int n, nx, ny, result = 0, max_sum = 0, max_count = 4;
int forest[4][4];
int visited[4][4] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int count, int sum){
    if(count == max_count){
        if(result < max_sum)
            result = max_sum;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                for(int k = 0; k < 4; k++){
                    nx = j + dx[k];
                    ny = i + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        visited[i][j] = 1;
                        DFS(count+1, sum + forest[i][j] + forest[ny][nx]);
                        visited[i][j] = 0;
                    }
                }
                visited[i][j]=0;
            }
        }
    }
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &forest[i][j]);
        }
    }

    if(n == 2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                result += forest[i][j];
            }
        }
    }
    else{
        DFS(0, 0);
    }

    printf("%d", result);

    return 0;
}