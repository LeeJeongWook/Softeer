#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct{
    int num;    //참가자 번호
    int score;  //점수
    int rank;   //순위
}rate;

int N;
rate rate_arr[MAX];
int final_rate[MAX];


int Score_Compare(const void *a, const void *b) {
    return ((rate*)b)->score - ((rate*)a)->score;
}

int Num_Compare(const void *a, const void *b){
    return ((rate*)a)->num - ((rate*)b)->num;
}

int main(){
    /* Input: 참가자의 수 N */
    scanf("%d", &N);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; j++){
            rate_arr[j].num = j;
            /* Input: 참가자 N명의 점수 */
            scanf("%d", &rate_arr[j].score);
        }

        /* 오름차순으로 정렬 */
        qsort(rate_arr, N, sizeof(rate), Score_Compare);

        for(int k = 0; k < N; k++){
            rate_arr[k].rank = k + 1;
        }

        qsort(rate_arr, N, sizeof(rate), Num_Compare);

        for(int l = 0; l < N; l++){
            printf("%d ",rate_arr[l].rank);
        }
        // for(int f = 0; f < N; f++){
        //     printf("%d %d %d\n", rate_arr[f].num, rate_arr[f].score, rate_arr[f].rank);
        // }
        printf("\n");
    }

    return 0;
}