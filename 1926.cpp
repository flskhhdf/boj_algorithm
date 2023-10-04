#include <iostream>
#include <queue>
using namespace std;

int N,M;
int mapCnt = 0, mapArea, maxArea = 0;;
int map[501][501];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visit[501][501];
queue<pair<int,int>> q;

void BFS(int y, int x){
    mapArea = 1;
    q.push({y,x});
    visit[y][x] = true;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            pair<int,int> tmp = q.front();
            q.pop();
            for(int k = 0; k<4; k++){
                int nY = tmp.first + offset[k][0];
                int nX = tmp.second + offset[k][1];
                if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                    if(!visit[nY][nX] && map[nY][nX] == 1){
                        q.push({nY,nX});
                        visit[nY][nX] = true;
                        mapArea++;
                    }
                }
            }
        }
    }
    if(mapArea > maxArea) maxArea = mapArea;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(map[i][j] == 1 && !visit[i][j]) {
                BFS(i,j); 
                mapCnt++;
            }
        }
    }
    if(mapCnt == 0) maxArea = 0;
    cout << mapCnt << '\n' << maxArea << '\n';
}