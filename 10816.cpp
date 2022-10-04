#include "iostream"
#include <functional>
#include <map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,num,search_num;
	map<int, int> card;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> num;
		card[num] = ++card[num];
	}
	cin >> m;
	for(int i = 0; i<m; i++){
		cin >> search_num;
		cout << card[search_num] << ' ';
	}
}