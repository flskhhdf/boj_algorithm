#include "iostream"
#include "limits.h"
using namespace std;


int main(){
	int n,m,b,map[501][501],height,tmp,btime=INT_MAX;
	cin >> n >> m >> b;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 0; i<257; i++){
		int del = 0;
		int add = 0;
		for(int j = 0; j<n; j++){
			for(int k = 0; k<m; k++){
				tmp = map[j][k] - i;
				if(tmp > 0){
					del += tmp; 
				}
				else if (tmp < 0){
					add -= tmp;
				} 
				// cout << "i : " << i << '\n' << map[j][k] << ' ' << del << ' ' << add << '\n';
			}
		}
		if(del + b >= add){
			int mintime = del*2+add;
			if(btime >= mintime) {
				btime = mintime;
				height = i;
			}
		}
	}
	cout << btime << ' ' << height;
}	

