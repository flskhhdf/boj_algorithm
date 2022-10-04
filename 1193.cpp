#include "iostream"
using namespace std;

int main(){
	int n,idx=0;
	cin >> n; 
	while(n>0){
		idx++;
		n -= idx;
	}
	if(idx % 2 == 1) cout << 1-n << '/' << idx+n;
	else cout << idx + n << '/' << 1-n;
}

