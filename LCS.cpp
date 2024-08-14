#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string text1, text2;
    cin >> text1 >> text2; 

    int m = text1.length(), n = text2.length();
    int res;
    int dp[m + 1][n + 1] = {0};

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (text1[i] == text2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    res = dp[0][0];
    cout << "LCS : " << res;
}

