#include <stdio.h>

#define MAX 128

int H, W, Q;
int map[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/* Func: 이미지를 업데이트 */
void solution(int x, int y, int n) {
    int num = map[x][y];  /* 1.현재 픽셀의 색상 저장 */
    if(num == n) return;  /* 2.이미 바꿀 색과 같다면 처리하지 않음 */
    map[x][y] = n;  /* 3.색상 변경 */
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        /* 4.범위 내에 있으며 색상이 같을 때 재귀 호출 */
        if (0 <= nx && nx < H && 0 <= ny && ny < W && map[nx][ny] == num)
            solution(nx, ny, n);
    }
}

int main() {
    /* Input: 이미지 크기 */
    scanf("%d %d", &H, &W);

    /* Input: 이미지 */
    for (int k = 0; k < H; k++) {
        for (int l = 0; l < W; l++) {
            scanf("%d", &map[k][l]);
        }
    }

    /* Input: 연산 횟수 */
    scanf("%d", &Q);

    /* Input: 연산 */
    for (int k = 0; k < Q; k++) {
        int i, j, c;
        scanf("%d %d %d", &i, &j, &c);
        i--, j--;  /* 1-based 인덱스를 0-based로 변환 */
        solution(i, j, c);  /* 1.이미지 업데이트 */
    }

    /* Output: 최종 이미지 */
    for (int k = 0; k < H; k++) {
        for (int l = 0; l < W; l++) {
            printf("%d ", map[k][l]);
        }
        printf("\n");
    }

    return 0;
}
