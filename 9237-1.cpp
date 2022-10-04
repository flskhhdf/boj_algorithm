#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	int n,S[100000],res,max=0;
	cin>>n;
	for (int i=0; i<n; i++) {
	cin>>S[i];
	}

	sort(S,S+n,greater<>());
	for (int i=0; i<n; i++) {
		res=i+S[i]+1;
		if(res > max) max = res;
	}
	
	cout << max+1;
}