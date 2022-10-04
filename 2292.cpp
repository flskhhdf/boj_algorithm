#include "iostream"
using namespace std;

int main(){
	int n,temp=1,cnt=1,idx=6;
	cin >> n;
	while(n>temp){
		temp += idx;
		cnt++;
		idx+=6;
	}
	cout << cnt;
}