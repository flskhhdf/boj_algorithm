#include "iostream"
using namespace std;

int main(){
	int n,tenT=0,fT=0,oT=0,fH=0,oH=0;
	cin >> n;
	while(n > 0){
		if(n - 10000 >= 0){ n -= 10000; tenT++;}
		else if (n - 5000 >= 0) { n -= 5000; fT++;}
		else if (n - 1000 >= 0) { n -= 1000; oT++;}
		else if (n - 500 >= 0) { n -= 500; fH++;}
		else if (n - 100 >= 0) { n -= 100; oH++;}
	}
	cout << tenT << ' ' << fT << ' ' << oT << ' ' << fH << ' ' << oH; 
}