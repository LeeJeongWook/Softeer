#include <stdio.h>

int n, m;
int x[3], y[3]; // ģ������ ���� ��ġ
int dx[4] = {-1, 1, 0, 0}; // ��, ��, ��, �� �̵�
int dy[4] = {0, 0, -1, 1};
int farm[20][20];
int visited[20][20];
int tmp_visited[20][20];
int max_fruit = 0; // �ִ� ��Ȯ��
int total = 0;

// DFS�� 3�� ���� ��Ȯ�� �� �ִ� �ִ� ���� ��Ȯ�� Ž��
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

        // ���ڸ� ����� �ʵ��� üũ�ϰ�, �湮���� ���� �����θ� �̵�
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0) {
            visited[nx][ny] = 1; // �湮 ǥ��
            DFS(idx, nx, ny, time + 1, collected + farm[nx][ny]);
            visited[nx][ny] = 0; // ��Ʈ��ŷ
        }
    }
}

int main() {
    /* Input: ����(��) ũ�� n, ģ�� �� m */
    scanf("%d %d", &n, &m);

    /* Input: ������ ���� ��Ȯ�� */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &farm[i][j]);
        }
    }

    /* Input: �� ģ���� ���� ��ġ ����(x, y) */
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--, y[i]--; // 1-based -> 0-based ��ȯ
    }
    

    /* �� ģ���� ó�� ��ġ���� ���Ÿ� ��Ȯ�ϰ� DFS Ž�� ���� */
    for (int i = 0; i < m; i++) {
        max_fruit = 0;
        visited[x[i]][y[i]] = 1; // ó�� ��ġ �湮 ó��
        DFS(i, x[i], y[i], 0, farm[x[i]][y[i]]); // 3�� ���� �ִ� ��Ȯ�� Ž��
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