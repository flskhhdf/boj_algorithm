#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,m,cnt=0;
    int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool visit[600][600];
    char map[600][600];
    queue<pair<int,int>> q;

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'I') {
                visit[i][j] = true;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < n && nX >= 0 && nX < m){
                if(!visit[nY][nX] && map[nY][nX] != 'X'){
                    if (map[nY][nX] == 'P') cnt++;
                    visit[nY][nX] = true;
                    q.push({nY,nX});
                }
            }
        }
    }
    if(cnt == 0) cout << "TT";
    else cout << cnt;
}