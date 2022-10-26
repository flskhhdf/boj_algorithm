#include "iostream"
using namespace std;
int k,n,m,arr[300][300];

int calc(int x1, int y1, int x2, int y2){
	int sum = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if((i >= x1-1 && j >= y1 - 1) && (i <= x2-1 && j <= y2 - 1)) sum += arr[i][j];
		}
	}
	return sum;
}

int main(){
	int x1,y1,x2,y2;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> arr[i][j]; 
		}
	}
	
	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<m; j++){
	// 		cout << arr[i][j] << ' '; 
	// 	}
	// 	cout << '\n';
	// }

	cin >> k;
	
	for(int i = 0; i<k; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << calc(x1,y1,x2,y2) << '\n';
	}
}