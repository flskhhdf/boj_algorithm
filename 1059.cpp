#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int l,s,n,start=0,end=0,cnt=0;
	vector<int> v;
	cin >> l;
	for(int i = 0; i<l; i++){
		cin >> s;
		v.push_back(s); 
	}
	cin >> n;

	for(int i = 0; i<l; i++){
		if(v[i] == n) {cout << 0; return 0;}
	}

	sort(v.begin(), v.end());

	for(int i = 0; i<l; i++){
		if(v[i] > n){
			start = v[i-1];
			end = v[i];
			break;
		}  
	}

	for(int i = start+1; i<end; i++){
		for(int j = i+1; j<end; j++){
			if(i <= n && j >= n) cnt++;
		}
	}
	cout << cnt;
}