#include "iostream"
#include "limits.h"
using namespace std;


int main(){
	int n,m,b,map[501][501],min =INT_MAX,max = 0,cnt=0,cnt1=0;
	cin >> n >> m >> b;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] < min) min = map[i][j];
			if(map[i][j] > max) max = map[i][j];
		}
	}


	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(map[i][j] > min && map[i][j] > 0) {
				map[i][j]--;
				cnt++;
				cout << "check" << '\n';
			}
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(map[i][j] < max ) {
				map[i][j]++;
				cnt1++;
			}
		}
	}
	

	cout << cnt << ' ' << cnt1 << '\n';

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}	

