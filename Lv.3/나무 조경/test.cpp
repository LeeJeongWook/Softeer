#include <iostream>
#include <algorithm>

using namespace std;

int N;
int temp_Cnt=0;
int answer;
int arr[5][5];
int visited[5][5];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void DFS_Recur(int cnt,int temp) {
    if(cnt==temp_Cnt) {
        answer=max(answer,temp);
        return;
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0) {
                visited[i][j]=1;
                
                int dx,dy;
                for(int k=0;k<4;k++) {
                    dx=i+dir[k][0];
                    dy=j+dir[k][1];
                    
                    if(dx<0 or dx>=N or dy<0 or dy>=N) {
                        continue;
                    }
                    
                    if(visited[dx][dy]==0) {
                        visited[dx][dy]=1;
                        DFS_Recur(cnt+1, temp+arr[i][j]+arr[dx][dy]);
                        visited[dx][dy]=0;
                    }
                }
                visited[i][j]=0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    if(N==2) {
        temp_Cnt=2;
    }
    else {
        temp_Cnt=4;
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    DFS_Recur(0, 0);
    
    cout << answer << "\n";
    
    return 0;
}