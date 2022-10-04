#include "iostream"
#include <queue>
using namespace std;

int main(){
	queue<pair<int, int>> q;
	int n,m,map[1000][1000],visit[1000][1000]={0},cnt=0;
	int offset[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
	cin >> m >> n;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] == -1) visit[i][j] = -1;
		}
	}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visit[i][j] == 0) {
                q.push({i, j});
                visit[i][j] = 1;
                while (!q.empty()) {
                    pair<int, int> tmp = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nY = tmp.first + offset[k][0];
                        int nX = tmp.second + offset[k][1];
                        if (nY >= 0 && nY < n && nX >= 0 && nX < m) {
                            if (map[nY][nX] == 0 && visit[nY][nX] == 0) {
                                q.push({nY, nX});
                                map[nY][nX] = 1;

                                for (int i = 0; i < n; i++) {
                                    for (int j = 0; j < m; j++) {
                                        cout << map[i][j] << ' ';
                                    }
                                    cout << "\n";
                                }
								cout << '\n';
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}

