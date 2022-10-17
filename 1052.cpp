#include "iostream"
using namespace std;

int main(){
	int n,k,cnt=0,idx,res=0;
	cin >> n >> k;
	int bcnt = n;
	
	if(n <= k) {cout << 0; return 0;}
	
	while(1){
		cnt = 0;
		bcnt = n;
		while(bcnt>0){
			if(bcnt % 2 == 1) cnt++;
			bcnt /= 2;
			// cout << cnt << '\n';
		}
		if(cnt <= k) break;
		n++;
		res++;
		// cout << n;
	}
	cout << res;
}