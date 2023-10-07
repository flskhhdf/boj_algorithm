#include "iostream"
#include <queue>
#include <vector>
using namespace std;

bool visit[100001];
int ans;
int cnt = 0;
int main(){
	int n,k;
	queue<pair<int,int>> q;
	cin >> n >> k;
	q.push({n,0});
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		if(tmp.first == k) { ans = tmp.second; cnt++;}
		if(!visit[tmp.first]){
			visit[tmp.first] = true;	
			if(tmp.first+1 < 100001 && tmp.first+1 >= 0) q.push({tmp.first+1, tmp.second + 1}); visit[tmp.first+1]; 
			if(tmp.first*2 < 100001 && tmp.first*2 >= 0) q.push({tmp.first*2, tmp.second + 1}); visit[tmp.first*2]; 
			if(tmp.first-1 < 100001 && tmp.first-1 >= 0) q.push({tmp.first-1, tmp.second + 1}); visit[tmp.first-1];
		}
    }
    cout << ans << '\n' << cnt;
}