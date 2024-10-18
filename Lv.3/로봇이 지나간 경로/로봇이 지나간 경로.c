#include <stdio.h>
#define MAX 25

int H, W, nx, ny, idx;
int visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};  //상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'^', 'v', '<', '>'};
char direction;
char grid[MAX][MAX];
char order[1000];

void Direction(int x, int y){
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(0 <= nx && nx < H && 0 <= ny && ny < W && visited[nx][ny] == 0){
            direction = dir[i];
        }
    }
}

void DFS(int x, int y){

}

int main(){
    /* Input: 격자판의 세로 H, 가로 W */
    scanf("%d %d", &H, &W);

    /* Input: 방문한 곳(#), 방문하지 않은 곳(.) */
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j] == '#' && visited[i][j] == 0){
                //Direction(i, j);
                //printf("i: %d j: %d dir: %c\n", i, j, direction);
                DFS(i, j);
            }
        }
    }


    // //grid 출력
    // for(int i = 0; i < H; i++){
    //     for(int j = 0; j < W; j++){
    //         printf("%c", grid[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}