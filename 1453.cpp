#include "iostream"
using namespace std;

int main(){
	int n,k,cnt=0;
	bool arr[100]={0};
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> k;
		if(arr[k-1] == true) cnt++;
		arr[k-1] = true; 
	}
	cout << cnt;
}