#include "iostream"
#include <vector>
using namespace std;

int main(){
	vector<string> v;
	string input;
	int n,dc=0,ic=0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> input;
		v.push_back(input);
	}

	for(int i = 0; i<n-1; i++){
		if(v[i] < v[i+1]) ic++;
		else if (v[i] > v[i+1]) dc++; 
	}
	if(ic == n-1) cout << "INCREASING";
	else if (dc == n-1) cout << "DECREASING" ;
	else cout << "NEITHER";
}