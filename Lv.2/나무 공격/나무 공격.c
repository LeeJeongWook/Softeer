#include <stdio.h>

int n, m, l, r, cnt = 0;
int field[100][100];

int main(void){
    scanf("%d %d", &n, &m);

    /* 1. 격자 및 파괴범 생성 */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &field[i][j]);
            /* 1.1. 파괴범의 수 만큼 cnt증가 */
            if(field[i][j])
                cnt++;
        }
    }

    /* 2. 두 번의 공격으로 파괴범 제거 */
    for(int i = 0; i < 2; i++){
        scanf("%d %d", &l, &r);
        /* 2.1. 왼쪽부터 오른쪽으로 파괴범 탐색 */
        for(int j = l - 1; j < r; j++){
            for(int k = 0; k < m; k++){
                /* 2.2. 제거할 경우 cnt감소, 탐색 중지 */
                if(field[j][k] == 1){
                    field[j][k] = 0;
                    cnt--;
                    break;
                }
            }
        }
    }

    printf("%d", cnt);
    
    return 0;
}