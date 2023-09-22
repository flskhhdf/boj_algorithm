#include "iostream"
#include <queue>
using namespace std;

int map[1001][1001],visit[1001][1001]={0};

int main(){
	int n,m,day = 0, cnt = 0 ;
	int offset[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
	queue<pair<int,int>> q;

	cin >> m >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j] == 1) q.push({i,j});		
			else if (map[i][j] == 0) cnt++;
		}
	}

	while(!q.empty()){
		int qSize = q.size();
		while(qSize--){
			pair<int,int> tmp = q.front();
			visit[tmp.first][tmp.second] = 1;
			q.pop();
				
			for(int k = 0; k<4; k++){
				int nY = offset[k][0] + tmp.first;
				int nX = offset[k][1] + tmp.second;

				if(nY >= 0 && nY < n && nX >=0 && nX < m){
					if(visit[nY][nX] == 0 && map[nY][nX] == 0){
						map[nY][nX] = 1;
						q.push({nY,nX});
					}
				} 
			}
		}
		day++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << day-1;
}