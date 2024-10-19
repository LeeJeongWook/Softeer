#include <stdio.h>

#define MAX 128

int H, W, Q;
int map[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/* Func: �̹����� ������Ʈ */
void solution(int x, int y, int n) {
    int num = map[x][y];  /* 1.���� �ȼ��� ���� ���� */
    if(num == n) return;  /* 2.�̹� �ٲ� ���� ���ٸ� ó������ ���� */
    map[x][y] = n;  /* 3.���� ���� */
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        /* 4.���� ���� ������ ������ ���� �� ��� ȣ�� */
        if (0 <= nx && nx < H && 0 <= ny && ny < W && map[nx][ny] == num)
            solution(nx, ny, n);
    }
}

int main() {
    /* Input: �̹��� ũ�� */
    scanf("%d %d", &H, &W);

    /* Input: �̹��� */
    for (int k = 0; k < H; k++) {
        for (int l = 0; l < W; l++) {
            scanf("%d", &map[k][l]);
        }
    }

    /* Input: ���� Ƚ�� */
    scanf("%d", &Q);

    /* Input: ���� */
    for (int k = 0; k < Q; k++) {
        int i, j, c;
        scanf("%d %d %d", &i, &j, &c);
        i--, j--;  /* 1-based �ε����� 0-based�� ��ȯ */
        solution(i, j, c);  /* 1.�̹��� ������Ʈ */
    }

    /* Output: ���� �̹��� */
    for (int k = 0; k < H; k++) {
        for (int l = 0; l < W; l++) {
            printf("%d ", map[k][l]);
        }
        printf("\n");
    }

    return 0;
}
