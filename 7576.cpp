#include "iostream"
#include <queue>
using namespace std;

int main(){
	int n,m,map[1001][1001],offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}},cnt=0,nY,nX;
	bool visit[1001][1001];
	queue<pair<int,int>> q;
	queue<pair<int,int>> qq;

	cin >> m >> n;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] == 1) q.push({i,j});
		}
	}
	
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		for(int i = 0; i<4; i++){
			nY = tmp.first + offset[i][0];
			nX = tmp.second + offset[i][1];
			if(nY >=0 && nY < n && nX >=0 && nX < m){
				if(visit[nY][nX] == 0 && map[nY][nX] == 0){
					map[nY][nX] = 1;
					visit[nY][nX] = 1;
				}
			}
		}

		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "=======================\n";

	}

}