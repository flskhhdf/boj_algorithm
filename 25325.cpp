#include "iostream"
#include <utility>
using namespace std;

int main(){
	int n;
	cin >> n;
	pair<string, int> p[n];
	string name[n];
	int cnt[n];
	for(int i = 0; i<n; i++){
		string name[i];
		cnt[i] = 0;
		p[i].first = name[i];
		p[i].second = cnt[i]; 
	}
}