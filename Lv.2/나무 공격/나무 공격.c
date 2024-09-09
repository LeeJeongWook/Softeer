#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int n, m, l1, l2, r1, r2, cnt = 0;
    int field[100][100];
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &field[i][j]);
        }
    }

    scanf("%d %d", &l1, &r1);
    scanf("%d %d", &l2, &r2);

    for(int i = l1-1; i < r1; i++){
        for(int j = 0; j < m; j++){
            if(field[i][j] == 1){
                field[i][j] = 0;
                break;
            }
        }
    }

    for(int i = l2-1; i < r2; i++){
        for(int j = 0; j < m; j++){
            if(field[i][j] == 1){
                field[i][j] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(field[i][j] == 1)
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}