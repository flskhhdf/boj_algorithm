#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N,M;
int map[301][301];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visit[301][301];
queue<pair<int,int>> q;

void BFS(){
    vector<pair<pair<int,int>,int>> v;
    while(!q.empty()){
        int zCnt = 0;
        pair<int,int> tmp = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(map[nY][nX] == 0){
                    zCnt++;
                }
            }
        }
        v.push_back({{tmp.first,tmp.second},zCnt});
    }
    
    int vSize = v.size();

    for(int i = 0; i<vSize; i++){
        map[v[i].first.first][v[i].first.second] -= v[i].second;
        if(map[v[i].first.first][v[i].first.second] <= 0 ) map[v[i].first.first][v[i].first.second] = 0;
        else q.push({v[i].first.first, v[i].first.second});
    }
}

void isCrack(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        visit[tmp.first][tmp.second] = true;
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(!visit[nY][nX] && map[nY][nX] != 0) { visit[nY][nX] = true; q.push({nY,nX});}
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] != 0) { q.push({i,j}); }
        }
    }

    int year = 0;

    while(1){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "===================\n";

        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        // 빙산 덩이 구하기
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(!visit[i][j] && map[i][j] != 0)  { isCrack(i, j); cnt++; }
            }
        }

        if(cnt == 0) { cout << 0; break;}
        else if (cnt >= 2) { cout << year; break;}

        BFS();
        year++;
    }
}