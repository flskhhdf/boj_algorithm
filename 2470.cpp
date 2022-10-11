#include "iostream"
#include "algorithm"
#include "limits.h"
using namespace std;

int main(){
	pair<int,int> p;
	int n,num[100001],max=INT_MAX;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> num[i];
	}

	sort(num,num+n);

	int left = 0, right = n-1;

	while(left < right){
		int sum = num[left] + num[right];
		
		if(abs(sum) < abs(max)) {
			max = sum;
			p.first = num[left];
			p.second = num[right];
		}

		if(sum < 0) left++;
		else right--;
	}
	cout << p.first << ' ' << p.second;
}