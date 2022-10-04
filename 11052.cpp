#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	int n,p[10000];
	double empt[10000];
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >>p[i];
		empt[i] = (double)p[i]/(i+1);
	}
	sort(empt, empt+n);
	for(int i = 0; i<n; i++){
		cout << empt[i] << ' ';
	}
	cout << empt[n-1]*n;
}