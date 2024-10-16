#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct{
    int num;    //참가자 번호
    int score;  //점수
    int rank;   //순위
}rate;

typedef struct{
    int num;
    int rank;
}final_rate;

int N, rank_tmp;
rate rate_arr[MAX];
final_rate final_rate_arr[MAX];



int Score_Compare(const void *a, const void *b) {
    return ((rate*)b)->score - ((rate*)a)->score;
}

int Num_Compare(const void *a, const void *b){
    return ((rate*)a)->num - ((rate*)b)->num;
}

int Rate_Compare(const void *a, const void *b){
    return ((final_rate *)a)->rank - ((final_rate *)b)->rank;
}

int main(){
    /* Input: 참가자의 수 N */
    rank_tmp = 0;
    scanf("%d", &N);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; j++){
            rate_arr[j].num = j;
            /* Input: 참가자 N명의 점수 */
            scanf("%d", &rate_arr[j].score);
        }

        /* 오름차순으로 정렬 */
        qsort(rate_arr, N, sizeof(rate), Score_Compare);
        
        for(int k = 1; k <= N; k++){
            /* 점수가 같으면 동일한 순위 */
            if(rate_arr[k].score == rate_arr[k+1].score){
                rate_arr[k].rank = k - rank_tmp;
                rank_tmp++;
            }
            else{
                rank_tmp = 0;
                rate_arr[k].rank = k;
            }
        }

        qsort(rate_arr, N, sizeof(rate), Num_Compare);

        
        for(int l = 0; l < N; l++){
            printf("%d ", rate_arr[l].rank);
            final_rate_arr[l].num = l + 1;
            final_rate_arr[l].rank += rate_arr[l].rank;
        }

        printf("\n");
    }
    
    qsort(final_rate_arr, N, sizeof(final_rate), Rate_Compare);

    for(int i = 0; i < N; i++)
        printf("%d ", final_rate_arr[i].num);

    return 0;
}