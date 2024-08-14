#include <iostream>
#include <queue>
using namespace std;

int N,M;
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char map[101][101];
bool visit[101][101];
int wCnt = 0, bCnt = 0, wSum = 0, bSum = 0;

void BFS(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    wCnt = 0, bCnt = 0;
    
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        visit[tmp.first][tmp.second] = true;

        if(map[tmp.first][tmp.second] == 'W') wCnt++;
        else if(map[tmp.first][tmp.second] == 'B') bCnt++;
        
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(!visit[nY][nX] && (map[tmp.first][tmp.second] == map[nY][nX])){
                    q.push({nY,nX});
                    visit[nY][nX] = true;   
                }
            }
        }
    }
    wSum += wCnt*wCnt;
    bSum += bCnt*bCnt;
}

int main(){
    cin >> M >> N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(!visit[i][j]) BFS(i,j);
        }
    }

    cout << wSum << ' ' << bSum << '\n';
}