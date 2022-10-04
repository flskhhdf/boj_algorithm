#include "iostream"
#include <ios>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,idx=0,num=0,sum=0;
	int res[1000001];
	cin >> n;
	for(int i = 1; i<=1000000; i++){
		sum=i;
		num=i;
		while(num!=0){
			sum = sum + (num%10);
			num /= 10;
		}
		res[i] = sum;
	}
	for(int i = 1; i<=1000000; i++){
		if(res[i] == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}