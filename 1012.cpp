#include "iostream"
#include <queue>
#include <utility>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		queue<pair<int,int>> q;
		int n,m,k,map[50][50]={0},x,y,cnt=0;
		int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
		bool visit[50][50] = { 0 };

		cin >> m >> n >> k;
		
		for(int i = 0; i<k; i++){
			cin >> x >> y;
			map[y][x] = 1;
		}

        for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(map[i][j] == 1){
					// printf("[%d, %d]\n", i, j);
					q.push({i,j});
					map[i][j] = 0;
					while(!q.empty()){
						pair<int, int> tmp = q.front();
						q.pop();
						for(int k = 0; k<4; k++){
							int nY = tmp.first + offset[k][0];
							int nX = tmp.second + offset[k][1];
							if(nY >= 0 && nY < n && nX >=0 && nX < m){
								if(map[nY][nX]== 1){
									q.push({nY,nX});
									map[nY][nX] = 0;
								}
							}
						}
					}
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		
	}
}