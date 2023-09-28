#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N;
int map[21][21];
int sharkSize = 2;
int eatCnt = 0, res = 0, idx = 0;
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visit[21][21];
bool isEat = false;
bool isStop = false;
int curX,curY;
vector<pair<int,pair<int,int>>> v;
queue<pair<pair<int,int>, int>> q;

void BFS(int y, int x){
    int eatTime;
    q.push({{y,x},0});
    while(!q.empty()){
        pair<int,int> tmp = q.front().first;
        visit[tmp.first][tmp.second] = true;
        int cnt = q.front().second;
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < N && nX >= 0 && nX < N && !visit[nY][nX]){
                if(map[nY][nX] <= sharkSize) { // 먹거나 이동 가능한 상태
                    if(!isEat && map[nY][nX] < sharkSize && nY == v[idx].second.first && nX == v[idx].second.second){ // 먹을수 있는데 위치가 왼쪽 위인것 우선  
                        map[nY][nX] = 0;
                        curX = nX;
                        curY = nY;
                        isEat = true;
                        idx++;
                        eatTime = cnt+1;
                        res += eatTime;
                        for(int i = 0; i<N; i++){
                            for(int j = 0; j<N; j++){
                                cout << map[i][j] << ' ';
                            }
                            cout << '\n';
                        }
                        cout << "=======================\n";
                    }
                    else {
                        q.push({{nY,nX}, cnt+1});
                        visit[nY][nX] = true;   
                    }
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
            if(map[i][j] != 0){
                if(map[i][j] == 9){
                    curX = j;
                    curY = i;
                    map[i][j] = 0;
                }
                else v.push_back({map[i][j],{i,j}});
            }
        }
    }

    sort(v.begin(), v.end());
    
    int vSize = v.size();

    for(int i = 0; i<vSize; i++){
        // cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << '\n';
    }

    while(!isStop){        
        memset(visit,0,sizeof(visit));
        BFS(curY, curX);
        if(isEat){
            isEat = false;
            eatCnt++;
            if(eatCnt == sharkSize) { sharkSize++; eatCnt = 0; }
        }
        else {
            isStop = true;
        }
    }
    cout << res;
}

