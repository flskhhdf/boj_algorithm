#include "iostream"
using namespace std;

int main(){
	double x,y;
	int z,n,cnt=0;
	cin >> x >> y;
	z = (y*100)/x;
	if(z >= 99){ cout << -1; return 0;}
	int left = 0, right = 1000000000;
	while(left<=right){
		int mid = (left+right)/2;
		int newZ = (100*(y+mid))/(x+mid);
		if(z >= newZ){
			cnt = mid + 1;
			left = mid + 1;
		}
		else right = mid-1;
	}
	cout << cnt;
}