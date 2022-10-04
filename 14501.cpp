#include "iostream"
using namespace std;

int main(){
	int n,t[17],p[17],dp[17]={0};
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> t[i] >> p[i];
	}
	for(int i = n; i>0; i--){
		if(i+t[i]-1>n) {
			dp[i] = dp[i+1];
		}
		else dp[i] = max(p[i]+dp[i+t[i]],dp[i+1]);
	}
	cout << dp[1];
}