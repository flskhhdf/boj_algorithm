#include "iostream"
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
	queue<pair<int,int>> q;
	string input[25];
	int n,map[25][25],idx=0,cnt=0;
	int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 기준으로 상하좌우 위치 정하기
	bool visit[25][25]={0};
	vector<int> v;

	cin >> n;
	for(int i = 0; i<n; i++) cin >> input[i];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			map[i][j] = input[i][j]-'0';
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(map[i][j] == 1 && visit[i][j] == 0){ 
				// BFS 실행조건
				int home = 1;
				cnt++;
				visit[i][j] = 1;
				q.push({i,j}); // 입력은 y, x 순서로 받았다.
				while(!q.empty()){
					pair<int,int> tmp = q.front(); // 기준 좌표 저장해주고
					q.pop(); // 들어와있는거 빼기
					for(int k = 0; k<4; k++){ // 상하좌우이므로 4번 반복 
						int nY = tmp.first + offset[k][0]; // y값의 다음 좌표; nextY
						int nX = tmp.second + offset[k][1]; // x값의 다음 좌표, nextX 
						if(nY >= 0 && nY < n && nX >=0 && nX < n) { // 정상 범위.
							if(map[nY][nX] == 1 && visit[nY][nX] == 0){
								q.push({nY,nX}); // 좌표 입력
								visit[nY][nX] = 1; // 방문 체크
								home++;
							}
						} 
					}
				}
				v.push_back(home);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for(int i = 0; i<cnt; i++){
		cout << v[i] << '\n';
	} 
}