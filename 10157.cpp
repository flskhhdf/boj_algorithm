#include "iostream"
#include "string.h"
#include <ios>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	bool flag = 0;
	int n,m,k,map[1001][1001],col,row,dir=1,idx=1;
	cin >> n >> m >> k;

	memset(map,-1,sizeof(map));

	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			map[i][j] = 0;
		}
	}

	col = m;
	row = 0;
	while(map[col][row] != n*m){

		if(dir == 1){
			if(map[col-1][row] == 0 && col > 0) {
				map[col-1][row] = idx++;
				col--;
			}
			else dir = 2;
		}

		else if(dir == 2){	
			if(map[col][row+1] == 0){
				map[col][row+1] = idx++;
				row++;
			}
			else dir = 3;
		}

		else if (dir == 3){
			if(map[col+1][row] == 0){
				map[col+1][row] = idx++;
				col++;
			}
			else dir = 4;
		}

		else if(dir == 4){
			if(map[col][row-1] == 0){
				map[col][row-1] = idx++;
				row--;
			}
			else dir = 1;
		}
		if(map[col][row] == k){
			cout << row+1 << ' ' << m-col;
			return 0;
		}
	}
	cout << 0;
}