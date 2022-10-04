#include "iostream"
#include "queue"
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

queue<pair<int,int>> q;
bool visit[25][25] ={0};
int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}, map[25][25];
vector<int> v;

void bfs(int y, int x, int n){
	q.push({y,x});
	int home=1;
	visit[y][x] = 1;
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		for(int i = 0; i<4; i++){
			int nY = tmp.first + offset[i][0];
			int nX = tmp.second + offset[i][1];
			if(nY >=0 && nY < n && nX >= 0 && nX < n){
				if(map[nY][nX] == 1 && visit[nY][nX] == 0){
					visit[nY][nX] = 1;
					q.push({nY, nX});
					home++;
				}
			}
		}
	}
	v.push_back(home);
}

int main(){
	string input[25];
	int n,cnt=0;
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
				// printf("%d %d\n", i, j);
				bfs(i,j,n);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for(int i = 0; i<cnt; i++){
		cout << v[i] <<'\n';
	}
}