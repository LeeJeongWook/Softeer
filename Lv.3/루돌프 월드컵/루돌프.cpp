#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int, int> arr[7] = {
    {0, 0},
    {1, 2},
    {1, 3},
    {1, 4},
    {2, 3},
    {2, 4},
    {3, 4}
};

double ans;
double F[6];
double prob[6][6][3];

void dfs(int k, int rst, double tot, vector<int>& score){
    int a = arr[k].first;
    int b = arr[k].second;
    double p = (rst == -1) ? 1.0 : prob[a][b][rst];
    vector<int> tmp = score;
    if (rst == 0)
        score[a] += 3;
    else if (rst == 1)
        score[b] += 3;
    else if (rst == 2)
        score[a]++, score[b]++;
    
    if (k == 6){
        auto f = score;
        sort(f.begin() + 1, f.end());
        if (score[1] >= f[3]){
            ans += tot * p;
        }
    }
    else{
        dfs(k + 1, 0, tot * p, score);
        dfs(k + 1, 1, tot * p, score);
        dfs(k + 1, 2, tot * p, score);
    }
    score = tmp;
}

int main(int argc, char** argv){
    for (int i = 1; i <= 4; i++)
        cin >> F[i];
    
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            if (i == j) continue;
            prob[i][j][0] = F[i] * 4.0 / (F[i] * 5.0 + F[j] * 5.0);
            prob[i][j][1] = F[j] * 4.0 / (F[i] * 5.0 + F[j] * 5.0);
            prob[i][j][2] = (F[i] + F[j]) / (F[i] * 5.0 + F[j] * 5.0);
        }
    }
    
    vector<int> score = { 0, 0, 0, 0, 0 };
    
    dfs(0, -1, 1.0, score);
    
    ans = ans * 100'000.0;
    ans = round(ans);
    ans = ans / 1000.0;
    
    cout << ans;
    
    return 0;
}

