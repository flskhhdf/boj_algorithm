#include "iostream"
#include "vector"
#include <utility>
#include <vector>
#include "algorithm"
using namespace std;

int main(){
	vector<pair<int, int>> v;

	for(int i = 0; i<10; i++){
		v.push_back({i,i});
	}

	sort(v.begin(), v.end());

	for(int i = 0; i<v.size(); i++){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
