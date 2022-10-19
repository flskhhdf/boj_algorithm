#include "iostream"
#include "deque"
#include <vector>
#include "cmath"
#include "string.h"
using namespace std;
vector<deque<int>> wheel(1001);
bool visit[1001];
int dir[1001];
int o;

void isRotation(int w, int d){
	dir[w] = d;
	visit[w] = true;

	if(w-1 > 0 && visit[w-1] == 0){
		if(d == 0) isRotation(w-1, 0);
		else if(wheel[w][6] == wheel[w-1][2]) isRotation(w-1, 0);
		else isRotation(w-1,-d);
	}

	if (w+1 <= o && visit[w+1] == 0){
		if(d == 0) isRotation(w+1, 0);
		else if(wheel[w][2] == wheel[w+1][6]) isRotation(w+1, 0);
		else isRotation(w+1,-d);
	}
}

void Rotation(){
	for(int i = 1; i<=o; i++){
		if(dir[i] == 0) continue;
		if(dir[i] == -1){
			int tmp = wheel[i].front();
			wheel[i].pop_front();
			wheel[i].push_back(tmp);
		}
		else {
			int tmp = wheel[i].back();
			wheel[i].pop_back();
			wheel[i].push_front(tmp);
		}
	}
}

int main(){

	cin >> o;
	char input;
	for(int i = 1; i<=o; i++){
		for(int j = 0; j<8; j++){
			cin >> input;
			wheel[i].push_back(input-'0');
		}
	}
	int k;
	int w,d;
	cin >> k;

	for(int a = 0; a<k; a++){
		cin >> w >> d; 
		memset(visit,0,sizeof(visit));
		isRotation(w, d);
		Rotation();
	}

	int ans=0;

	for(int i = 1; i<=o; i++){
		if(wheel[i][0] == 1) ans++; 
	}
	cout << ans;
}