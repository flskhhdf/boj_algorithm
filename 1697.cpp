#include "iostream"
#include <queue>
using namespace std;

int main(){
	int n,k;
	queue<pair<int,int>> q;
	cin >> n >> k;
	q.push({n,0});
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		if(tmp.first == k) {cout << tmp.second; return 0;}
		if(tmp.first*2 <= k) q.push({tmp.first*2,tmp.second+1});
		if(tmp.first+1 <= k) q.push({tmp.first+1,tmp.second+1});
		if(tmp.first-1 <= k) q.push({tmp.first-1,tmp.second+1});
		// cout << tmp.first << ' ' << tmp.second << '\n';
	}
}