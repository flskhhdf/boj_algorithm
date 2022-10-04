#include "iostream"
#include "string.h"
#include <ios>
#include <utility>
using namespace std;

int main(){
	//상1 우2 하3 좌4

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	pair<int, int> p;
	int n,k,map[1000][1000],dir=3;
	cin >> n >> k;
	memset(map,-1,sizeof(map));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			map[i][j] = 0;
		}
	}

	int num = n*n;
	map[0][0] = num;
	int row=0,col=0;

	while(map[col][row] != 1){

		if (dir == 3){ //처음은 아래로. 모두 0으로 초기화 되어있으니 아래로 가다 0이 아닌 좌표가 나오면 오른쪽으로
			if(map[col+1][row] == 0){ // 아래가 0일 경우
				map[col+1][row] = --num;
				col++;
			} 
			else dir = 2;
			// cout << col << ' ' << row << '\n'; 
		}	

		else if (dir == 2){
			if(map[col][row+1] == 0){
				map[col][row+1] = --num;
				row++;
			}
			else dir = 1;
			// cout << col << ' ' << row << '\n'; 
		}

		else if (dir == 1){
			if(map[col-1][row] == 0 && col > 0){
				map[col-1][row] = --num;
				col--;
			}
			else dir = 4;
			// cout << col << ' ' << row << '\n'; 
		} 

		else if (dir == 4){
			if(map[col][row-1] == 0){
				map[col][row-1] = --num;
				row--;
			}
			else dir = 3;
		}
		if(map[col][row] == k){ 
			p.first = col;
			p.second = row;
		}
	}



	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout << map[i][j] << ' ';
			if(map[i][j] == k) {
				p.first = i+1;
				p.second = j+1;
			}
		}
		cout << '\n';
	}
	cout << p.first << ' ' << p.second;
}