#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n,left,right;
	long long arr[5000],sum,min = 3000000001,temp[5000];
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}

	sort(arr,arr+n);

	for(int i = 0; i<n-2; i++){
		left = i+1;
		right = n-1;
		while(left < right){
			sum = arr[i] + arr[left] + arr[right];
			if(abs(sum) < min){
				min = abs(sum);
				temp[0] = arr[i];
				temp[1] = arr[left];
				temp[2] = arr[right];
			}
			else if (sum > 0) right--;
			else left++;
		}
	}

	for(int i = 0; i<3; i++){
		cout << temp[i] << ' ';
	}
}