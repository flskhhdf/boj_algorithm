#include "iostream"
#include <queue>
#include "cstring"
using namespace std;

char map[12][6];
bool visit[12][6] = {false};
int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}},pcnt=1,cnt=0,idx,ccnt=0;
queue<pair<int,int>> q;
queue<pair<int,int>> qq;
bool flag, pcheck=true;

void down(int i, int j){
	idx = 11;
	while(idx > i){
		if(map[idx][j] == '.'){
			map[idx][j] = map[i][j];
			map[i][j] = '.';
			break;
		}
		else idx--;
	}
}

void bfs(int i, int j){
	pcnt = 1;
	visit[i][j] = true;
	q.push({i,j});
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		if(pcnt == 1) qq.push({tmp.first,tmp.second});
		for(int k = 0; k<4; k++){
			int nY = tmp.first + offset[k][0];
			int nX = tmp.second + offset[k][1];
			if(nY < 12 && nY >=0 && nX >= 0 && nX <6){
				if(visit[nY][nX] == 0 && map[tmp.first][tmp.second] == map[nY][nX]){
					q.push({nY,nX});
					qq.push({nY,nX});
					visit[nY][nX] = 1;
					pcnt++;
				}
			}
		}
	}

	while(!qq.empty()){
		pair<int,int> pos = qq.front();
		if(pcnt >= 4){
			map[pos.first][pos.second] ='.';
			pcheck = true;
		}
		qq.pop();
	}
}

int main(){

	for(int i = 0; i<12; i++){
		for(int j = 0; j<6; j++){
			cin >> map[i][j];
		}	
	}

	while(pcheck){
		pcheck = false;	

		memset(visit,0,sizeof(visit));
		for(int i = 0; i<12; i++){
			for(int j = 0; j<6; j++){
				if(visit[i][j] == 0 && map[i][j] != '.'){
					bfs(i,j);
				}
			}
		}
		cnt++;
		for(int i = 11; i>=0; i--){
			for(int j = 0; j<6; j++){
				if(map[i][j] != '.'){
					down(i,j);
				}
			}
		}
		ccnt++;
	}
	if(ccnt == 1) cout << 0;
	else cout << cnt-1;
}