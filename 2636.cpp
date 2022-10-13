#include "iostream"
#include "stack"
#include <queue>
#include "cstring"
using namespace std;

int main() {
    int n, m, map[101][101], offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},min=2147483647;
    int nY, nX, cnt=0, ccnt;
	bool flag = 1;
    bool visit[101][101] = {false};
    queue<pair<int, int>> q;
    stack<pair<int, int>> s;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
	int tc = 3;
	while(flag){
		memset(visit,0,sizeof(visit));
		ccnt = 0;
		q.push({0, 0});
		visit[0][0] = 1;



		while (!q.empty()) {
			pair<int, int> tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				nY = tmp.first + offset[i][0];
				nX = tmp.second + offset[i][1];
				if (nY >= 0 && nY < n && nX >= 0 && nX < m) {
					if (visit[nY][nX] == 0) {
						if (map[nY][nX] == 1) s.push({nY, nX});
						else q.push({nY, nX});
						visit[nY][nX] = 1;
					}
				}
			}
		}

		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(map[i][j] == 1) {
					ccnt++;
				}
			}
		}

		while(!s.empty()){
			pair<int, int> pos = s.top();
			map[pos.first][pos.second] = 0;
			s.pop();
		}

		if(ccnt > 0 && ccnt < min) min = ccnt;

		for(int i = 0; i<n; i++){
			flag = 0;
			for(int j = 0; j<m; j++){
				if(map[i][j] == 1) {flag = 1; break;}
			}
			if(flag) break;
		}

		cnt++;
	}
	cout << cnt << '\n' << min;
}
