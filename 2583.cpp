#include "iostream"
#include <queue>
#include "algorithm"
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	int n,m,k,map[101][101]={0},Lx,Ly,Rx,Ry,offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}},cnt=0,sicnt=0;
	bool visit[101][101] = {0};
	queue<pair<int,int>> q;
	
	cin >> m >> n >> k; // n열 m 행
	int si[k];

	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<m; j++){
	// 		cout << map[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	for(int i = 0; i<k; i++){
		cin >> Lx >> Ly >> Rx >> Ry;	
		for(int j = Ly; j<Ry; j++){
			for(int l = Lx; l<Rx; l++){
				map[j][l] = 1;
			}
		}
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			if(map[i][j] == 0 && visit[i][j] == 0){
				q.push({i,j});
				sicnt=1;
				visit[i][j] = 1;
				cnt++;
				while(!q.empty()){
					pair<int,int> tmp = q.front();
					q.pop();
					for(int k = 0; k<4; k++){
						int nY = tmp.first + offset[k][0];
						int nX = tmp.second + offset[k][1];
						if(nY >= 0 && nY < m && nX >= 0 && nX < n){
							if(map[nY][nX] == 0 && visit[nY][nX] == 0){
								q.push({nY,nX});
								visit[nY][nX] = 1;
								sicnt++;
								// printf("(%d, %d)\n", nY, nX);
							}
						}
					}
                }
				v.push_back(sicnt);
                // for (int i = 0; i < m; i++) {
                //     for (int j = 0; j < n; j++) {
                //         cout << visit[i][j] << ' ';
                //     }
                //     cout << '\n';
                // }
				// cout << '\n';
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for(int i = 0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
}