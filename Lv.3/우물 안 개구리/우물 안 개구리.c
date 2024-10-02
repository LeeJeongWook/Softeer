#include <stdio.h>

typedef struct{
    int A;
    int B;
}relation;

int a, b, N, M, ans = 0;
int W[100000];
int check[100000];
relation relationship[100000];

int main(){
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++)
        scanf("%d", &W[i]);

    /* 1. 누구와도 친분이 없는 멤버 체크 */
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        relationship[i].A = a;
        relationship[i].B = b;
        /* 1.1. 친분이 없는 멤버는 0 한 사람이라도 친분이 있다면 1 */
        if(check[a - 1] == 0)
            check[a - 1] = 1;
        if(check[b - 1] == 0)
            check[b - 1] = 1;
    }

    /* 2. 친분이 있는 멤버끼리 중량 비교 */
    for(int i = 0; i < M; i++){
        a = relationship[i].A - 1;
        b = relationship[i].B - 1;
        /* 2.1. 자신이 더 무겁게 든다면 0 무게가 같거나 적으면 2 */
        /* 2.2. 2일 경우 한 명 이상 무겁게 드는 사람이 있으므로 최고라고 생각할 수 없음*/
        if(W[a] > W[b]){
            if(check[a] == 1)
                check[a] = 0;
            check[b] = 2;
        }
        else if(W[a] < W[b]){
            check[a] = 2;
            if(check[b] == 1)
                check[b] = 0;
        }
        else if(W[a] == W[b]){
            check[a] = 2;
            check[b] = 2;
        }
    }

    for(int i = 0; i < N; i++){
        if(check[i] == 0)
            ans++;
    }

    printf("%d", ans);

    return 0;
}