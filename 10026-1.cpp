#include "iostream"
#include "queue"
#include "cstring"
#include <utility>
using namespace std;

queue<pair<int,int>> q;
int n,offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool visit[101][101] = {0};
char map[101][101];

void BFS(int x, int y){

    q.push({x, y});
    visit[x][y] = 1;
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if (nY >= 0 && nY < n && nX >= 0 && nX < n) {
                if (map[nY][nX] == map[tmp.first][tmp.second] && visit[nY][nX] == 0) {
                    q.push({nY, nX});
                    visit[nY][nX] = 1;
                }
            }
        }
    }
}

int main(){

	int cnt=0,Bcnt=0;
	cin >> n;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(visit[i][j] == 0){
				BFS(i, j);
				cnt++;
			}
		}
	}

	memset(visit,0,sizeof(visit));

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(map[i][j] == 'G') map[i][j] = 'R';
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(visit[i][j] == 0){
				BFS(i, j);
				Bcnt++;
			}
		}
	}

	cout << cnt << ' ' << Bcnt;
}