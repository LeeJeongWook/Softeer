#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct coordinate{
    int x;
    int y;
};

int n, m, ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int field[5][5];
int visited[5][5] = {0, };
struct coordinate dest[16];

void DFS(struct coordinate cur, int index){
    if(cur.x == dest[index].x && cur.y == dest[index].y){
        index++;
        if(index == m){
            ans++;
            return;
        }
    }
    visited[cur.x][cur.y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(visited[nx][ny] == 0 && field[nx][ny] == 0){
                struct coordinate next = {nx, ny};
                DFS(next, index);
            }
        }
    }
    visited[cur.x][cur.y] = 0;
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &field[i][j]);
        }
    }

    int x, y;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        dest[i].x = x - 1;
        dest[i].y = y - 1;
    }

    DFS(dest[0], 0);

    printf("%d", ans);

    return 0;
}