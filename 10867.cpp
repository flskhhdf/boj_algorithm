#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	int n,num,cnt=0;
	bool visit[2001]={0};
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> num;
		if(visit[1000+num] == 0) {
			visit[1000+num] = 1;
			cnt++;
		}
	}

	int arr[cnt],idx=0;
	for(int i = 0; i<2001; i++){
		// cout << visit[i] << '\n';
		if(visit[i] == 1) {
			arr[idx++] = i-1000;
		}
	}
	sort(arr,arr+cnt);

	for(int i = 0; i<idx; i++){
		cout << arr[i] << '\n';
	}
}