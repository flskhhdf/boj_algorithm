#include "iostream"
#include "queue"
#include <cstddef>
#include <utility>
using namespace std;

int main(){
	queue<pair<int, int>> q;
	int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
	int n,m,map[100][100];
	int visit[100][100] = {0};
	string input[100];
	cin >> n >> m;
	for(int i = 0; i<n; i++) cin >> input[i];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			map[i][j] = input[i][j]-'0';
		}
	}

    q.push({0, 0});
    visit[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if (nY >= 0 && nY < n && nX >= 0 && nX < m) {
                if (map[nY][nX] == 1 && visit[nY][nX] == 0) {
                    q.push({nY, nX});
                    visit[nY][nX] = visit[tmp.first][tmp.second] + 1;
                }
            }
        }
    }
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		printf("%d ", visit[i][j]);
	// 	}
	// 	printf("\n");
	// }

    cout << visit[n-1][m-1];
}