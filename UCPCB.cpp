#include "iostream"
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;


int main(){
	int n,m,w[100001],v[100001],idx=0;
	float mix[100001],res=0;
	pair<float, int> p[100001];

	cin >> n >> m;

	for(int i = 0; i<n; i++){
		cin >> w[i] >> v[i];
	}

	for(int i = 0; i<n; i++){
		mix[i] = (float)v[i]/w[i];
		p[i] = make_pair(mix[i], i);
	}

	sort(p,p+n,greater<>());

	for(int i = 0; i<n; i++){
		cout << "first " << p[i].first << '\n';
		cout << "second " << p[i].second << '\n';
	}

	while(1){
		for(int i = 0; i<w[p[idx].second]; i++){
			res += p[idx].first; 
			m--;
			if(m==0) {
				cout << res;
				return 0;
			}
		}
		idx++;
	}
}