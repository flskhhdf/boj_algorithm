#include "iostream"
#include "queue"
using namespace std;

int main(){
	int n,m,cnt=0;
	queue<pair<long,long>> q;
	cin >> n >> m;
	q.push({n,cnt});
	while(!q.empty()){
		pair<long,long> tmp = q.front();
		q.pop();
		if(tmp.first == m) {cout << tmp.second+1; return 0;}
		if(tmp.first*2 <= m) q.push({tmp.first*2,tmp.second+1});
		if(tmp.first*10+1 <= m) q.push({tmp.first*10+1,tmp.second+1});
	}
	cout << -1;
}