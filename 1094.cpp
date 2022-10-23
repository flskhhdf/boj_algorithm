#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

int main(){
	int n,cnt=0;
	cin >> n;
	while(n){
		if(n%2 == 1) cnt++;
		n /= 2;
	}
	cout << cnt;
}