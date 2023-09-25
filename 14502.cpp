#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int map[9][9];
bool visit[9][9];
int offset[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int n,m;
queue<pair<int,int>> q;
vector<pair<int,int>> v;

void BFS(){
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        visit[tmp.first][tmp.second] = true;
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < n && nX >=0 && nX < m){
                if(!visit[nY][nX] && map[nY][nX] == 0){
                    q.push({nY,nX});
                    visit[nY][nX] = true;
                }
            }
        }
    }
}

int main(){
    int cnt = 0, ans = 0;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) { q.push({i,j}); }
            else if (map[i][j] == 0) {v.push_back({i,j});}
        }
    }

    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<i; j++){
            for(int k = 0; k<j; k++){
                int cnt = 0;

                map[v[i].first][v[i].second] = 1;
                map[v[j].first][v[j].second] = 1;
                map[v[k].first][v[k].second] = 1;

                memset(visit, false, sizeof(visit));

                BFS();

                for(int l = 0; l<n; l++){
                    for(int o = 0; o<m; o++){
                        if(map[l][o] == 0 && !visit[l][o]) cnt++;
                        else if (map[l][o] == 2) q.push({l,o});
                    }
                }

                ans = max(ans,cnt);

                map[v[i].first][v[i].second] = 0;
                map[v[j].first][v[j].second] = 0;
                map[v[k].first][v[k].second] = 0;
            }
        }
    }
    cout << ans;
}

