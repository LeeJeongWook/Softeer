#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;  /* ���� */
    int index;  /* �ε���(������) */
} Rank;

/* Func: ������ �������� �������� ���� */
int compare(const void *a, const void *b) {
    return ((Rank *)b)->score - ((Rank *)a)->score;
}

/* Func: ��ȸ�� ��� ��� */
void calculate_rank(int scores[], int ranks[], int N) {
    Rank *ranking = (Rank *)malloc(N * sizeof(Rank));
    
    for (int i = 0; i < N; i++) {
        ranking[i].index = i;
        ranking[i].score = scores[i];
    }

    /* 1.������ ������������ ���� */
    qsort(ranking, N, sizeof(Rank), compare);

    /* 2.��� ��� */
    for (int i = 0; i < N; i++) {
        if (i > 0 && ranking[i].score == ranking[i - 1].score)
            ranks[ranking[i].index] = ranks[ranking[i - 1].index];  /* 2.1.������ ��� ���� ��� */
        else
            ranks[ranking[i].index] = i + 1;    /* 2.2.(������ ������ ���� ��� + 1) �� */
    }

    free(ranking);
}

int main() {
    /* Input: �������� �� */
    int N;
    scanf("%d", &N);

    int scores[3][N];
    int ranks[3][N];
    int total_scores[N];
    int total_ranks[N];

    /* Input: �� ��ȸ�� ���� */
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &scores[i][j]);

    /* 1.��ȸ�� ��� ��� */
    for (int i = 0; i < 3; i++)
        calculate_rank(scores[i], ranks[i], N);

    /* 2.�����ں��� �� ��ȸ�� ������ �ջ� */
    for (int i = 0; i < N; i++)
        total_scores[i] = scores[0][i] + scores[1][i] + scores[2][i];

    /* 3.���� ��� ��� */
    calculate_rank(total_scores, total_ranks, N);

    /* Output: �� ��ȸ�� ��� */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", ranks[i][j]);
        }
        printf("\n");
    }

    /* Output: ���� ��� */
    for (int i = 0; i < N; i++)
        printf("%d ", total_ranks[i]);

    return 0;
}