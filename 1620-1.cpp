#include "iostream"
#include <algorithm>
#include <cctype>
#include <string>
#include <utility>
using namespace std;
 
int main(){
	int n,m;
	pair<string, int> pokemon[100000];
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> pokemon[i].first;
	}
	string value;
	sort(pokemon,pokemon+n);
	for(int i = 0; i<m; i++){
		cin >> value;
		if(isdigit(value[0])){
			int num = stoi(value);
			cout << pokemon[num].first;
		}
		else {
			if(binary_search(pokemon,pokemon+n,value)){
				
			}
		}
	}

}