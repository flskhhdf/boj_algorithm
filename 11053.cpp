#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,dp[1001];
    cin >> n;
    int arr[n];
    
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    sort(dp, dp+n);
    cout << dp[n-1];
}