#include <stdio.h>

int n, m, l, r, cnt = 0;
int field[100][100];

int main(void){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &field[i][j]);
            if(field[i][j])
                cnt++;
        }
    }

    for(int i = 0; i < 2; i++){
        scanf("%d %d", &l, &r);
        for(int j = l - 1; j < r; j++){
            for(int k = 0; k < m; k++){
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