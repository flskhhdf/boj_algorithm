#include "iostream"
using namespace std;

int main(){
	int n,m,j,k;
	
	cin >> n >> m;

	int matA[100][100];
	int matB[100][100];
	
	for(int i = 0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> matA[i][j];
		}
	}

	cin >> j >> k;

	
	
	for(int i = 0; i<j; i++){
		for(int j=0; j<k; j++){
			cin >> matB[i][j];
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<k; j++){
			int sum = 0;
			for(int l=0; l<m; l++){
				sum += matA[i][l] * matB[l][j];
			}
			cout << sum << ' ';
		}
		cout << '\n';
	}

	
}
