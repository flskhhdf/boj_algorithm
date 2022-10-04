#include "iostream"
using namespace std;

int main(){
	int n,num=0,cnt=0;
	cin >> n;

	while(cnt != n){
		num++;
		int temp = num;
		while(temp != 0){
			if(temp%1000 == 666){
				cnt++;
				break;
			}
			else temp/=10;
		}
	}
	cout << num;
}