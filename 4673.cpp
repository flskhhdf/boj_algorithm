#include "iostream"
using namespace std;

int main(){
	int num,sum;
	bool arr[100001]={0};
	for(int i = 1; i<=10000; i++){
		num = i;
		sum = i;
		while(num!=0){
			sum = sum + (num%10);
			num /= 10;
		}
		arr[sum] = true;	
	}
	for(int i = 1; i<=10000; i++){
		if(arr[i] == false) cout << i << '\n';
	}
}
