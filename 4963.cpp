#include "iostream"
#include "queue"
using namespace std;

int main(){
	
	while(1){
		int n,m,map[50][50],offset[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}},cnt=0;
		bool visit[50][50] = {0};
		queue<pair<int,int>> q;
		
		cin >> m >> n;
		if(m == 0 && n == 0) return 0;
		else {
			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					cin >> map[i][j];
				}
			}

			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					if(map[i][j] == 1 && visit[i][j] == 0){
						cnt++;
						q.push({i,j});
						visit[i][j] = 1;
						while(!q.empty()){
							pair<int,int> tmp = q.front();
							q.pop();
							for(int k = 0; k<8; k++){
								int nY = tmp.first + offset[k][0];
								int nX = tmp.second + offset[k][1];
								if(nY >= 0 && nY < n && nX >= 0 && nX <m){
									if(map[nY][nX] == 1 && visit[nY][nX] == 0){
										q.push({nY,nX});
										visit[nY][nX] = 1;
									}
								}
							}
						}
					}	
				}
			}
			cout << cnt << '\n';
		}
	}
}