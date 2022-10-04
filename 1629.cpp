#include "iostream"
#include <ios>
using namespace std;

long long a,b,c,n;

long long pow(long long b){

	if (b == 0) return 1;
	if (b == 1) return a%c;

	n = pow(b/2)%c;
	
	if(b%2==0) return n*n%c;
	else return n*n%c*a%c;  
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	cin >> a >> b >> c;
	cout << pow(b);
}