#include "iostream"
#include <queue>
#include <vector>
using namespace std;
bool visit[100001];
int main(){
	int n,k;
	queue<pair<int,int>> q;
	vector<pair<int,int>> v;
	cin >> n >> k;
	q.push({n,0});
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		if(tmp.first == k) {cout << tmp.second; return 0;}
		if(tmp.first*2 <= k && !visit[tmp.first*2]) {q.push({tmp.first*2,tmp.second+1}); visit[tmp.first*2] = true;} 
		if(tmp.first+1 <= k && !visit[tmp.first+1]) {q.push({tmp.first+1,tmp.second+1}); visit[tmp.first+1] = true;}
		if(tmp.first-1 <= k && !visit[tmp.first-1]) {q.push({tmp.first-1,tmp.second+1}); visit[tmp.first-1] = true;}
	}
}