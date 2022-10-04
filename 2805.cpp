#include "iostream"
#include "limits.h"
#include <ios>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int n,m,min=1,max=0,sum=0,h,ans=0;
	cin >> n >> m;
	long long int height[n];
	for(int i = 0; i<n; i++){
		cin >> height[i];
		if(height[i] > max) max = height[i];
	}
	
	while(min <= max){
		h = (max + min)/2;
		sum = 0;
		for(int i = 0; i<n; i++){
			if(height[i]>h) sum += height[i]-h;	
		}
		if(sum >= m) {
			min = h+1;
			if(h > ans) ans = h;
		}	
		else{
			max = h-1;
		}
	}
	cout << ans;
}