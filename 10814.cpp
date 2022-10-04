#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main(){
	// int arr[10] = {2,234,652,23,4,67,48,1234,515,132};
	// sort(arr,arr+10,compare);
	// for(int i = 0; i<10; i++){
	// 	cout << arr[i] << ' ';
	// }
	int n,age;
	string name;
	cin >> n;
	vector<pair<int,string>> v;
	for(int i = 0; i<n; i++){
		cin >> age >> name;
		v.push_back({age,name});
	}

	stable_sort(v.begin(), v.end(), compare);

	for(int i = 0; i<n; i++){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}