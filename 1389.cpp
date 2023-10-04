#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N,M;
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string map[51];
queue<pair<int,int>> q;
bool visit[51][51];
int len[51][51];
int Max = 0;

int BFS(int y, int x){
    len[y][x] = 1;
    q.push({y,x});
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(map[nY][nX] == 'L' && !visit[nY][nX]){
                    q.push({nY,nX});
                    visit[nY][nX] = true;
                    len[nY][nX] = len[tmp.first][tmp.second] + 1;
                    if(Max < len[nY][nX]) Max = len[nY][nX];
                }
            }
        } 
    }
    return Max - 1;
}

int main(){
    int res = 0;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> map[i];
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(map[i][j] == 'L'){
                memset(visit,0,sizeof(visit));
                memset(len,0,sizeof(len));
                visit[i][j] = true;
                int tmp = BFS(i,j);
                if(res < tmp) res = tmp;    
            }
        }
    }
    cout << res;
}