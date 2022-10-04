#include "iostream"
#include <ios>
using namespace std;
int map[5][5];

bool check(){
	int row,col,diagR=0,diagL=0;
	int bingo=0;

	for(int i = 0; i<5; i++){
		row = 0;
		col = 0;
		for(int j = 0; j<5; j++){
			if(map[i][j] == 0) row++;
			if(map[j][i] == 0) col++;
		}
		if(col == 5) bingo++;
		if(row == 5) bingo++;
		if(map[i][i] == 0) diagR++;
		if(map[i][4-i] == 0) diagL++;
	}
	if(diagR == 5) bingo++;
	if(diagL == 5) bingo++;
	if(bingo>=3) return true;
	return false;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int res;
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 0; i<25; i++){
		cin >> res;
		for(int j = 0; j<5; j++){
			for(int k = 0; k<5; k++){
				if(map[j][k] == res) map[j][k] = 0;
			}
		}
		if(check()) {
			cout << i+1;
			return 0;
		}
	}

}