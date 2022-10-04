#include "iostream"
#include "algorithm"
using namespace std;

int main(){
    int n,max=0,arr[100001],idx;
    cin >> n;
	idx=n;
    for(int i = 0; i<n; i++){
		cin >> arr[i];
    }
	sort(arr, arr+n);

	for(int i = 0; i<n; i++){
		if(arr[i]*idx > max) max = arr[i]*idx;
		idx--; 
	}
	cout << max;
}