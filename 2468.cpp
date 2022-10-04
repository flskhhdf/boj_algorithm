#include "iostream"
#include "limits.h"
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	queue<pair<int,int>> q;
	int n,map[101][101],max=0,min=INT_MAX,offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}},cnt=0,maxCnt=0;;
	cin >> n;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] > max) max = map[i][j];
			if(map[i][j] < min) min = map[i][j];
		}
	}
	
	for(int i=0; i<max; i++){
		bool visit[101][101] ={0};
		cnt = 0;

		for(int j = 0; j<n; j++){
			for(int k = 0; k<n; k++){
				if(map[j][k] <= i ) map[j][k] = 0;
			}
		}

		for(int j = 0; j<n; j++){
			for(int k = 0; k<n; k++){
				if(map[j][k] != 0 && visit[j][k] == 0){

					q.push({j,k});
					visit[j][k] = 1;

					while(!q.empty()){
						pair<int,int> tmp = q.front();
						q.pop();
						for(int l=0; l<4; l++){
							int nY = tmp.first + offset[l][0];
							int nX = tmp.second + offset[l][1];

							if(nY >= 0 && nY < n && nX >=0 && nX <n){
								if(map[nY][nX] != 0 && visit[nY][nX] == 0){
									q.push({nY,nX});
									visit[nY][nX] = 1;
								}
							}
						}
					}
					cnt++;
					if(cnt > maxCnt) maxCnt = cnt;
					// for(int y = 0; y < n; y++){
					// 	for(int x = 0; x<n; x++){
					// 		cout << visit[y][x] << ' ';
					// 	}
					// 	cout << '\n';
					// }
					// cout << '\n';
				}
			}
		}		
	}
	cout << maxCnt << '\n';
}