#include "iostream"
#include <algorithm>
using namespace std;

int main(){
	int n,stair[301],dp[301];
	cin >>  n;
	for(int i = 0; i<n; i++){
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0]+stair[2],stair[1]+stair[2]);
	for(int i = 0; i<3; i++){
		cout << dp[i] << '\n';
	}
	for(int i = 3; i<n; i++){
		dp[i] = max(dp[i-2]+stair[i],dp[i-3]+stair[i]+stair[i-1]);
		cout << dp[i] << '\n';
	}
	cout << dp[n-1];
}