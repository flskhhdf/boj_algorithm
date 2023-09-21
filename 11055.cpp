#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, arr[1001],dp[1001];
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+arr[i]);
            }
        }
    }
    sort(dp, dp+n);
    cout << dp[n-1];
}
