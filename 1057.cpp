#include "iostream"
#include "math.h"
#include <ios>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	double k,l;
	int n,cnt=0;

	cin >> n >> k >> l;

	while(k != l){
		k =  ceil(k/2);
		l = ceil(l/2);
		cnt++;
	}
    cout << cnt;
	// 67%?
}
