#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	bool flag=false;
	int n,max=0;
	cin >> n;
	int len[n];
	for(int i = 0; i<n; i++){
		cin >> len[i];
	}
	sort(len,len+n);
	for(int i = 0; i<n-2; i++){
		if(len[i]+len[i+1] > len[i+2]){
			if(max < len[i]+len[i+1]+len[i+2]){
				max = len[i]+len[i+1]+len[i+2];
				flag = true;
			} 
		}
	}
	if(flag) cout << max;
	else cout << -1;
}