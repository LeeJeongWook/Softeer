#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;  /* 점수 */
    int index;  /* 인덱스(참가자) */
} Rank;

/* Func: 점수를 기준으로 내림차순 정렬 */
int compare(const void *a, const void *b) {
    return ((Rank *)b)->score - ((Rank *)a)->score;
}

/* Func: 대회별 등수 계산 */
void calculate_rank(int scores[], int ranks[], int N) {
    Rank *ranking = (Rank *)malloc(N * sizeof(Rank));
    
    for (int i = 0; i < N; i++) {
        ranking[i].index = i;
        ranking[i].score = scores[i];
    }

    /* 1.점수를 내림차순으로 정렬 */
    qsort(ranking, N, sizeof(Rank), compare);

    /* 2.등수 계산 */
    for (int i = 0; i < N; i++) {
        if (i > 0 && ranking[i].score == ranking[i - 1].score)
            ranks[ranking[i].index] = ranks[ranking[i - 1].index];  /* 2.1.동점인 경우 같은 등수 */
        else
            ranks[ranking[i].index] = i + 1;    /* 2.2.(나보다 점수가 높은 사람 + 1) 등 */
    }

    free(ranking);
}

int main() {
    /* Input: 참가자의 수 */
    int N;
    scanf("%d", &N);

    int scores[3][N];
    int ranks[3][N];
    int total_scores[N];
    int total_ranks[N];

    /* Input: 각 대회의 점수 */
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &scores[i][j]);

    /* 1.대회별 등수 계산 */
    for (int i = 0; i < 3; i++)
        calculate_rank(scores[i], ranks[i], N);

    /* 2.참가자별로 세 대회의 점수를 합산 */
    for (int i = 0; i < N; i++)
        total_scores[i] = scores[0][i] + scores[1][i] + scores[2][i];

    /* 3.최종 등수 계산 */
    calculate_rank(total_scores, total_ranks, N);

    /* Output: 각 대회별 등수 */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", ranks[i][j]);
        }
        printf("\n");
    }

    /* Output: 최종 등수 */
    for (int i = 0; i < N; i++)
        printf("%d ", total_ranks[i]);

    return 0;
}