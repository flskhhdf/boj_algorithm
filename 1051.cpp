#include "iostream"
using namespace std;

int main(){
	int n,m,min,ans=1,max=0;
	string string[50];
	int squ[50][50];
	cin >> n >> m;
	n > m ? min = m : min = n;
	for(int i = 0; i<n; i++){
		cin >> string[i];
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			squ[i][j] = string[i][j]-'0';
		}
	}
	for(int k = 1; k<min; k++){
		for(int i = 0; i<n-k; i++){		
			for(int j = 0; j<m-k; j++){
				if(squ[i][j] == squ[i][j+k] && squ[i][j] == squ[i+k][j] && squ[i][j] == squ[i+k][j+k]){
					ans = (k+1)*(k+1);
					if(ans > max) max = ans;
				}
			}
		}
	}
	cout << ans;
}