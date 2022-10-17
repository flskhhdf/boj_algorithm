#include "iostream"
#include "queue"
#include <algorithm>
#include <queue>
using namespace std;

int n,m,map[51][51],offset[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
queue<pair<int,int>> q;

void bfs(){
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		for(int i = 0; i<8; i++){
			int nY = tmp.first + offset[i][0];
			int nX = tmp.second + offset[i][1];
			if(nY >= 0 && nY < n && nX >= 0 && nX < m){
				if(!map[nY][nX]) {
					q.push({nY,nX});
					map[nY][nX] = map[tmp.first][tmp.second] + 1;
				}
			}
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

int main(){
	int max = 0;

	cin >> n >> m;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j]) q.push({i,j});
		}
	}
	
	bfs();

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << map[i][j] << ' ';
			if(map[i][j] > max) max = map[i][j];
		}
		cout << '\n';
	}
	cout << max-1;
}