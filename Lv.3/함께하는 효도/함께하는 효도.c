#include <stdio.h>

int n, m;
int x[3], y[3]; // 친구들의 시작 위치
int dx[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우 이동
int dy[4] = {0, 0, -1, 1};
int farm[20][20];
int visited[20][20];
int tmp_visited[20][20];
int max_fruit = 0; // 최대 수확량
int total = 0;

// DFS로 3초 동안 수확할 수 있는 최대 열매 수확량 탐색
void DFS(int idx, int x, int y, int time, int collected) {
    if (time == 3) {
        if (collected > max_fruit) {
            max_fruit = collected;
            memcpy(tmp_visited, visited, sizeof(visited));
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 격자를 벗어나지 않도록 체크하고, 방문하지 않은 곳으로만 이동
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0) {
            visited[nx][ny] = 1; // 방문 표시
            DFS(idx, nx, ny, time + 1, collected + farm[nx][ny]);
            visited[nx][ny] = 0; // 백트래킹
        }
    }
}

int main() {
    /* Input: 격자(밭) 크기 n, 친구 수 m */
    scanf("%d %d", &n, &m);

    /* Input: 가능한 열매 수확량 */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &farm[i][j]);
        }
    }

    /* Input: 각 친구의 시작 위치 정보(x, y) */
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--, y[i]--; // 1-based -> 0-based 변환
    }
    

    /* 각 친구가 처음 위치에서 열매를 수확하고 DFS 탐색 시작 */
    for (int i = 0; i < m; i++) {
        max_fruit = 0;
        visited[x[i]][y[i]] = 1; // 처음 위치 방문 처리
        DFS(i, x[i], y[i], 0, farm[x[i]][y[i]]); // 3초 동안 최대 수확량 탐색
        total += max_fruit;
        memcpy(visited, tmp_visited, sizeof(tmp_visited));
        printf("-------\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d", visited[i][j]);
            }
            printf("\n");
        }
    }
    printf("%d\n", total);

    return 0;
}