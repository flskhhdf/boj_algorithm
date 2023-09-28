#include <iostream>
#include <queue>
using namespace std;

int N,M;
int map[1001][1001];
int visit[1001][1001][2];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string input[1001];
queue<pair<pair<int,int>,int>> q;

int BFS(){
    q.push({{0, 0}, 0});
    visit[0][0][0] = 1; // 벽을 안깼으면 0, 깼으면 1

    while(!q.empty()){
        pair<int,int> tmp = q.front().first;
        int wall = q.front().second;
        q.pop();

        if(tmp.first == N-1 && tmp.second == M-1) return visit[tmp.first][tmp.second][wall];

        for(int k = 0; k<4; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(!wall && map[nY][nX] == 1){
                    q.push({{nY,nX}, 1});
                    visit[nY][nX][wall+1] = visit[tmp.first][tmp.second][wall] + 1;
                }
                else if (map[nY][nX] == 0 && !visit[nY][nX][wall]){
                    q.push({{nY,nX}, wall});
                    visit[nY][nX][wall] = visit[tmp.first][tmp.second][wall] + 1;                    
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> input[i];
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) map[i][j] = input[i][j] - '0';
    }

    cout << BFS();
    // 배열에 벽을 부수었는가 부수지 않았는가를 나타내는 3차원을 추가
    // 만약에 벽을 부수었으면 block을 1로 바꾸어주고, 개수 추가
    // ==> 이 경우는 다음이 벽이고, 지금까지 부순 벽이 없을 때 이다
    
    // 다음이 벽이 아닐때
    // 그대로 진행하면 된다

    // 다음이 벽일 때 부쉈으면 부수지 않은 상태로 진행
}   