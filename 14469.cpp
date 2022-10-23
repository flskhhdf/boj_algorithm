#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<pair<int,int>> v;
	int n,arr,ent,sum=0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> arr >> ent;
		v.push_back({arr,ent});
	}
	sort(v.begin(), v.end());
	sum += v[0].first + v[0].second;
	for(int i = 1; i<n; i++) sum <= v[i].first ? sum = v[i].first + v[i].second : sum += v[i].second;
	cout << sum;
}