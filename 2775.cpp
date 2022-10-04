#include "iostream"
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		 int k,n,dp[15][15]={0},ans=0;
		cin >> k >> n;
		for(int i = 0; i<15; i++){
			dp[i][0] = 1;
			dp[0][i] = i+1;
		}

		for(int i = 1; i<k; i++){
			for(int j = 1; j<n; j++){
				for(int l = 0; l<j+1; l++){
					dp[i][j] += dp[i-1][l];
				}
			}
		}
		// for(int i = 0; i<k; i++){
		// 	for(int j = 0; j<n; j++){
		// 		cout << dp[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		for(int i = 0; i<n; i++){
			ans += dp[k-1][i];
		}
		cout << ans << '\n';
	}
}