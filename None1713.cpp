#include "iostream"
#include "queue"
#include <algorithm>
using namespace std;

int main(){

	queue<pair<int, int>> q;
	int n,m,k,visit[101]={0},max=0,idx=0;
	
	cin >> n >> m;

	for(int i = 0; i<m; i++){
		cin >> k;
		visit[k]++;
	}

	for(int i = 0; i<100; i++){
		if(visit[i] > 0) { 
			q.push({k,visit[k]});
		}
	}
	cout << max;
}