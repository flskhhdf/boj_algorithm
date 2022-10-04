#include "iostream"
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	int n;
	cin >> n;
	pair<int, int> p[n];
	for(int i = 0; i<n; i++){
		cin >> p[i].first >> p[i].second;
	}
	stable_sort(p,p+n);
	for(int i = 0; i<n; i++){
		cout << p[i].first << ' ' << p[i].second << '\n';
	}
}