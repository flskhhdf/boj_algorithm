#include "iostream"
#include "stack"
#include "queue"
#include "cstring"
using namespace std;

int main(){
	int n,m,map[101][101],visit[101][101],offset[4][2] = {{-1,0},{0,1},{1, 0},{0,-1}},check[101][101]={0},cnt=0;
	bool flag = 1;
	queue<pair<int,int>> q;
	stack<pair<int,int>> s;
	
	cin >> n >> m;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
		}
	}

	int tc = 5;
	while(flag){
		memset(visit,0,sizeof(visit));
		memset(check,0,sizeof(check));
		q.push({0,0});
		visit[0][0] = 1;

		while(!q.empty()){
			pair<int,int> tmp = q.front();
			q.pop();
			for(int i = 0; i<4; i++){
				int nY = tmp.first + offset[i][0];
				int nX = tmp.second + offset[i][1];
				if(nY >= 0 && nY < n && nX >= 0 && nX < m){
					if(visit[nY][nX] == 0) {
						if(map[nY][nX] == 0) { q.push({nY,nX}); visit[nY][nX]++; }
						else if (map[nY][nX] == 1){
							check[nY][nX]++;
						} 
					}
				}
			}
		}
		
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(check[i][j] > 1) {check[i][j] = 0; s.push({i,j});}
			}
		}

		while(!s.empty()){
			pair<int, int> pos = s.top();
			s.pop();
			map[pos.first][pos.second] = 0;
		}

		// for(int i = 0; i<n; i++){
		// 	for(int j = 0; j<m; j++){
		// 		cout << map[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';

		for(int i = 0; i<n; i++){
			flag = 0;
			for(int j = 0; j<m; j++){
				if(map[i][j] == 1) {flag = 1; break;}
			}
			if(flag) break;
		}
		cnt++;
	}
	cout << cnt;
}