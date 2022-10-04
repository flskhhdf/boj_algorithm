#include "iostream"
#include "queue"
#include "cstring"
#include <utility>
using namespace std;

int main(){
	queue<pair<int,int>> q;
	int n,offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}},r=0,g=0,b=0,Br=0,Bb=0;
	bool visit[101][101] = {0};
	string map[101], Bmap[101];
	
	cin >> n;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(map[i][j] == 'G') Bmap[i][j] = 'R'; 
			else Bmap[i][j] = map[i][j];
		}
	}
	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<n; j++){
	// 		cout << Bmap[i][j];
	// 	}
	// 	cout << '\n';
	// }

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(map[i][j] == 'R' && visit[i][j] == 0){
				r++;
				q.push({i,j});
				visit[i][j] = 0;
				while(!q.empty()){
					pair<int, int> tmp = q.front();
					q.pop();
					for(int k = 0; k<n; k++){
						int nY = tmp.first + offset[k][0];
						int nX = tmp.second + offset[k][1];
						if(nY >= 0 && nY < n && nX >= 0 && nX < n){
							if(map[nY][nX] == 'R' && visit[nY][nX] == 0){
								q.push({nY,nX});
								visit[nY][nX] = 1;
							}
						}
					}
				}
			}
			else if(map[i][j] == 'G' && visit[i][j] == 0){
				g++;
				q.push({i,j});
				visit[i][j] = 0;
				while(!q.empty()){
					pair<int, int> tmp = q.front();
					q.pop();
					for(int k = 0; k<n; k++){
						int nY = tmp.first + offset[k][0];
						int nX = tmp.second + offset[k][1];
						if(nY >= 0 && nY < n && nX >= 0 && nX < n){
							if(map[nY][nX] == 'G' && visit[nY][nX] == 0){
								q.push({nY,nX});
								visit[nY][nX] = 1;
							}
						}
					}
				}
			}

			else if(map[i][j] == 'B' && visit[i][j] == 0){
				b++;
				q.push({i,j});
				visit[i][j] = 0;
				while(!q.empty()){
					pair<int, int> tmp = q.front();
					q.pop();
					for(int k = 0; k<n; k++){
						int nY = tmp.first + offset[k][0];
						int nX = tmp.second + offset[k][1];
						if(nY >= 0 && nY < n && nX >= 0 && nX < n){
							if(map[nY][nX] == 'B' && visit[nY][nX] == 0){
								q.push({nY,nX});
								visit[nY][nX] = 1;
							}
						}
					}
				}
			}
		}
	}

	memset(visit,0,sizeof(visit));

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(Bmap[i][j] == 'R' && visit[i][j] == 0){
				Br++;
				q.push({i,j});
				visit[i][j] = 1;
				while(!q.empty()){
					pair<int, int> tmp = q.front();
					q.pop();
					for(int k = 0; k<4; k++){
						int nY = tmp.first + offset[k][0];
						int nX = tmp.second + offset[k][1];
						if(nY >=0 && nY < n && nX >=0 && nX < n){
							if(Bmap[nY][nX] == 'R' && visit[nY][nX] == 0){
								q.push({nY,nX});
								visit[nY][nX] = 1;
							}
						}
					}
				}
			}

			if(Bmap[i][j] == 'B' && visit[i][j] == 0){
				Bb++;
				q.push({i,j});
				visit[i][j] = 1;
				while(!q.empty()){
					pair<int, int> tmp = q.front();
					q.pop();
					for(int k = 0; k<4; k++){
						int nY = tmp.first + offset[k][0];
						int nX = tmp.second + offset[k][1];
						if(nY >=0 && nY < n && nX >=0 && nX < n){
							if(Bmap[nY][nX] == 'B' && visit[nY][nX] == 0){
								q.push({nY,nX});
								visit[nY][nX] = 1;
							}
						}
					}
				}
			}
		}
	}

	cout << r+g+b << ' ' << Br+Bb;
}