#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    int first;
    int second;
} Pair;

Pair arr[7] = {
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    {1, 2},
    {1, 3},
    {2, 3}
};

double ans;
double F[4];
double prob[4][4][3];

void dfs(int k, int rst, double tot, int* score){
    int a = arr[k].first;
    int b = arr[k].second;
    double p = (rst == -1) ? 1.0 : prob[a][b][rst];
    int score_tmp[4];
    memcpy(score_tmp, score, 4 * sizeof(int));

    if(rst == 0)
        score[a] += 3;
    else if(rst == 1)
        score[b] += 3;
    else if(rst == 2)
        score[a]++, score[b]++;

    if(k == 6) {
        int sort[4];
        memcpy(sort, score, 4 * sizeof(int));
        // 정렬 (오름차순)
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (sort[i] > sort[j]) {
                    int temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }
        if(score[0] >= sort[2])
            ans += tot * p;
    }
    else {
        dfs(k + 1, 0, tot * p, score);
        dfs(k + 1, 1, tot * p, score);
        dfs(k + 1, 2, tot * p, score);
    }
    memcpy(score, score_tmp, 4 * sizeof(int));
}

int main() {
    for (int i = 0; i < 4; i++)
        scanf("%lf", &F[i]);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;
            prob[i][j][0] = F[i] * 4.0 / (F[i] * 5.0 + F[j] * 5.0);
            prob[i][j][1] = F[j] * 4.0 / (F[i] * 5.0 + F[j] * 5.0);
            prob[i][j][2] = (F[i] + F[j]) / (F[i] * 5.0 + F[j] * 5.0);
        }
    }

    int score[4] = {0, 0, 0, 0};

    dfs(0, -1, 1.0, score);

    ans = round(ans * 100000) / 1000;

    printf("%.3lf\n", ans);

    return 0;
}
