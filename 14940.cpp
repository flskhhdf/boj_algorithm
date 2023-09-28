#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int output[1001][1001];
bool visit[1001][1001];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int cnt = 0;
queue<pair<int,int>> q;

int main(){
    int N,M;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) {q.push({i,j}); map[i][j] = 0; visit[i][j]=true;}
        }
    }

    while(!q.empty()){
        int qSize = q.size();
        cnt++;
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
                        map[nY][nX] = cnt;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visit[i][j] && map[i][j] == 1) map[i][j] = -1; 
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    
}