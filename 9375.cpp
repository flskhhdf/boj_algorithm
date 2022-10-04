#include "iostream"
#include <map>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		map<string, int> map;
		string name, kind;
		int n;
		cin >> n;
		for(int i = 0; i<n; i++){
			cin >> name >> kind;
			if(map.find(kind) == map.end()){
				map.insert({kind,1});
			}
			else map[kind]++;
		}
		int ans = 1;
		for(auto i:map){
			ans *= (i.second+1);
		}
		ans -= 1;
		cout << ans << '\n';
	}
}	