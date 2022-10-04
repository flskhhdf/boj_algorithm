#include "iostream"
#include <ios>
#include <map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	map<string, string> mp;
	string inputKey,inputValue,search;

	cin >> n >> m;
	
	for(int i = 0; i<n; i++){
		cin >> inputKey >> inputValue;
		mp.insert({inputKey,inputValue});	
	}

	for(int i = 0; i<m; i++){
		cin >> search;
		cout << mp[search] << '\n';
	}
}