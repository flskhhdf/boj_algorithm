#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	int pos[1000000];
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> pos[i];
	}
	sort(pos, pos+n);
	if(n%2==1) cout << pos[n/2];
	else cout << pos[n/2-1];
	// pair<int, int> p[100001];
	// int n,res,max=0;
	// long long sum=0;
	// int pos[100001];
	// cin >> n;
	// for(int i = 0; i<n; i++){
	// 	cin >> pos[i];
	// 	if(pos[i] > max) max = pos[i];
	// }

	// for(int i = 1; i<max+1; i++){
	// 	sum = 0;
	// 	for(int j = 0; j<n; j++){
	// 		res = pos[j] - i;
	// 		if(res < 0) res *=-1;
	// 		sum += res;
	// 	}
	// 	p[i].first = sum;
	// 	p[i].second = i;
	// }

	// sort(p, p+max+1);

	// cout << p[1].second;
}
