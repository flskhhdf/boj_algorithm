#include "iostream"
#include <cctype>
#include <string>
#include <utility>
#include "map"
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map <string, int> poke;
	string pokemon[100000];
	int n,m;
	cin >> n >> m;
	string pokename;
	for(int i = 1; i<=n; i++){
		string name;
		cin >> name;
		pokemon[i] = name;
		poke.insert({name,i});
	}

	for(int i = 0; i<m; i++){
		cin >> pokename;
		if(isdigit(pokename[0])){
			int num = stoi(pokename);
			cout << pokemon[num] << '\n';			
		}
		else {
			cout << poke[pokename] << '\n';
		}
	}
}