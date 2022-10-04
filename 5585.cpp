#include "iostream"
using namespace std;

int main(){
	int n,cnt=0;
	cin >> n;
	int res = 1000-n;
	while(res!=0){
		if(res >= 500){
			res-=500;
			cnt++;
		}
		else if(res >= 100){
			res-=100;
			cnt++;
		}
		else if(res >= 50){
			res-=50;
			cnt++;
		}
		else if(res >= 10){
			res-=10;
			cnt++;
		}
		else if(res >= 5){
			res-=5;
			cnt++;
		}
		else if(res >= 1){
			res-=1;
			cnt++;
		}
	}
	cout << cnt;
}