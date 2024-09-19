#include <stdio.h>

int N;
int max_cnt;
int result = 0;
int forest[4][4];
int visited[4][4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int cnt,int sum) {
    if(cnt == max_cnt) {
        if(result < sum)
            result = sum;
        return;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] == 0) {
                visited[i][j] = 1;
                
                for(int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if((nx >= 0 && nx < N && ny >= 0 && ny < N) && (visited[ny][nx] == 0)) {
                        visited[ny][nx] = 1;
                        DFS(cnt + 1, sum + forest[i][j] + forest[ny][nx]);
                        visited[ny][nx] = 0;
                    }
                }
                visited[i][j] = 0;
            }
        }
    }
}
int main() {
    
    scanf("%d", &N);
    
    if(N == 2) {
        max_cnt=2;
    }
    else {
        max_cnt=4;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &forest[i][j]);
        }
    }
    
    DFS(0, 0);
    
    printf("%d", result);
    
    return 0;
}