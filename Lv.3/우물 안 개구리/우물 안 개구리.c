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

    /* 1. �����͵� ģ���� ���� ��� üũ */
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        relationship[i].A = a;
        relationship[i].B = b;
        /* 1.1. ģ���� ���� ����� 0 �� ����̶� ģ���� �ִٸ� 1 */
        if(check[a - 1] == 0)
            check[a - 1] = 1;
        if(check[b - 1] == 0)
            check[b - 1] = 1;
    }

    /* 2. ģ���� �ִ� ������� �߷� �� */
    for(int i = 0; i < M; i++){
        a = relationship[i].A - 1;
        b = relationship[i].B - 1;
        /* 2.1. �ڽ��� �� ���̰� ��ٸ� 0 ���԰� ���ų� ������ 2 */
        /* 2.2. 2�� ��� �� �� �̻� ���̰� ��� ����� �����Ƿ� �ְ��� ������ �� ����*/
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