#include "iostream"
#include "queue"
#include <utility>
#include "algorithm"
using namespace std;

bool comp(int a, int b){
	return a>b;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		queue<pair<int, int>> q;
		int n,m,prio,cnt=0;

		cin >> n >> m;

		int arr[n];
		pair<int, int> p[n];
		
		for(int i = 0; i<n; i++){
			cin >> prio;
			arr[i] = prio;
			p[i].first = prio;
			p[i].second = i;
			q.push({p[i].first,p[i].second});
		}

		sort(arr, arr + n, comp);
		pair<int, int> tmp;

		for (int i = 0; i < n;) {
			tmp = q.front();
			if (arr[i] != tmp.first) {
				pair<int, int> cur = q.front();
				q.pop();
				q.push(cur);
			} else {
				cnt++;
				if (tmp.second == m) break;
				q.pop();
				i++;
			}
		}
		cout << cnt <<'\n';
	}
}