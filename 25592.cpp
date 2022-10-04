#include "iostream"
using namespace std;

int main(){
	int n,sum,idx=1;
		cin >> n;
		while(1){
			n -= idx++;
			if(n<0) break;
		}	
	if(idx % 2 == 0) cout << -n << '\n';
	else cout << 0 << '\n';
}
