#include "iostream"
using namespace std;

bool isPrime(int a){ 
	for(int i = 2; i<a; i++){
		if(a%i==0) {
			return false;
		} 
	}
	return true;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n,haf;
		cin >> n;
		haf = n/2;
		for(int i = 0; i<n/2; i++){
			if(isPrime(haf)){
				if(isPrime(n-haf)) cout << n-haf << ' ' << haf << '\n'; 
				break;
			}
			haf++;
		}
	}
}