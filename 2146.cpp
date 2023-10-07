#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
bool visit[101][101];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int cnt = 1;
int ans = 2147483647;
vector<pair<int, pair<int,int>>> v;

void BFS(int y, int x){
    queue<pair<int,int>> q; 
    visit[y][x] = true;
    q.push({y,x});

    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nY < N && nX >= 0 && nX < N && !visit[nY][nX]){
                if(map[nY][nX] == 1){
                    visit[nY][nX] = true;
                    q.push({nY,nX});
                } 
                else if (map[nY][nX] == 0){
                    v.push_back({cnt, {tmp.first,tmp.second}});
                }
            }
        }
    }
}

int main(){
    
    cin >> N;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(!visit[i][j] && map[i][j] == 1) { BFS(i,j); cnt++;}
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int vSize = v.size();    

    for(int i = 0; i<vSize-1; i++){
        for(int j = i+1; j < vSize; j++){
            if(v[i].first == v[j].first) continue;
            int absY = abs(v[i].second.first - v[j].second.first); 
            int absX = abs(v[i].second.second - v[j].second.second);
            int dis = absY + absX-1;
            if(ans>dis) ans = dis;
        }
    }
    cout << ans;
}