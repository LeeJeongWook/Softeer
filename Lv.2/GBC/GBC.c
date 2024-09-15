#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LENGTH_MAX 100

int main(){
    int N, M, limit_idx = 0, test_idx = 0, max_speed = 0;
    int limit_section[LENGTH_MAX];
    int limit_speed[LENGTH_MAX];
    int test_section[LENGTH_MAX];
    int test_speed[LENGTH_MAX];

    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++)
        scanf("%d %d", &limit_section[i], &limit_speed[i]);

    for(int i = 0; i < M; i++)
        scanf("%d %d", &test_section[i], &test_speed[i]);

    for(int i = 1; i <= LENGTH_MAX; i++){
        if(limit_speed[limit_idx] < test_speed[test_idx]){
            max_speed = max_speed < (test_speed[test_idx] - limit_speed[limit_idx]) ? (test_speed[test_idx] - limit_speed[limit_idx]) : max_speed;
        }
        if(limit_section[limit_idx] <= i){
            limit_idx++;
            limit_section[limit_idx] += i;
        }
        if(test_section[test_idx] <= i){
            test_idx++;
            test_section[test_idx] += i;
        }
    }

    printf("%d", max_speed);

    return 0;
}