#include "iostream"
#include "algorithm"
using namespace std;

int main(){
	int n,triangle[501][501];
	cin >> n;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<i+1; j++){
			cin >> triangle[i][j];
		}
	}

	for(int i = n-1; i>=0; i--){
		for(int j = 0; j<i; j++){
			triangle[i-1][j] += max(triangle[i][j],triangle[i][j+1]);
		}
	}

	cout << triangle[0][0];
}