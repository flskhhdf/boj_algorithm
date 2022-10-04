#include "iostream"
#include "limits.h"
#include <algorithm>
using namespace std;
string board[50];
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int WBcnt(int x, int y){
	int cnt=0;
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			if(board[x+i][y+j] != WB[i][j]) cnt++;
		}
	}
	return cnt;
}

int BWcnt(int x, int y){
	int cnt=0;
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			if(board[x+i][y+j] != BW[i][j]) cnt++;
		}
	}
	return cnt;
}

int main(){
	int n,m;
	int minres=INT_MAX;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> board[i];
	}

	for(int i = 0; i+8<=n; i++){
		for(int j = 0; j+8<=m; j++){
			int temp,wb,bw;
			wb = WBcnt(i,j);
			bw = BWcnt(i, j);
			wb < bw ? temp = wb : temp = bw;
			if(temp < minres) minres = temp;
		}
	}
	cout << minres;
}