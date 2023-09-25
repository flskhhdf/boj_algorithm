#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int N,M;
int map[1001][1001];
int visit[1001][1001] = {0};
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<int,int>> q;
vector<pair<int,int>> v;

void BFS(){
    q.push({0,0});
    visit[0][0] = 1;
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(visit[nY][nX] == 0 && map[nY][nX] == 0){
                    q.push({nY,nX});
                    visit[nY][nX] = visit[tmp.first][tmp.second] + 1;
                }
            }
        }
    }
}

int main(){
    int ans = 987654321;
    string input[1001];
    cin >> N >> M;
    for(int i = 0; i<N; i++) cin >> input[i];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) {
            map[i][j] = input[i][j] - '0';
            if(map[i][j] == 1) v.push_back({i,j});
        }
    }

    int vSize = v.size();

    if(vSize == 0) {
        BFS();
        cout << visit[N-1][M-1];
        return 0;
    }

    else {
        for(int i = 0; i<vSize; i++){
            map[v[i].first][v[i].second] = 0;

            memset(visit, 0, sizeof(visit));
            BFS();

            if(visit[N-1][M-1] != 0) { ans = min(ans, visit[N-1][M-1]);}
            map[v[i].first][v[i].second] = 1;
        }
    }
    if(ans == 987654321) cout << -1;
    else cout << ans;
}