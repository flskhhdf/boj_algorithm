#include "iostream"
using namespace std;

int main(){
	int n, m,arr[100][100]={0};
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			arr[i][j] += j;
		}
	}	

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
