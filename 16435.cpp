#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	int n,l;
	int h[10001];
	cin >> n >> l;
	for(int i = 0; i<n; i++){
		cin >> h[i];
	}
	sort(h,h+n);
	for(int i = 0; i<n; i++){
		if(l >= h[i]) l++;
	}
	cout << l;
}