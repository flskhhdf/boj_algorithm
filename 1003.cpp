#include "iostream"
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int zeroN[40] = {1, 0, 1, 0};
        int oneN[40] = {0, 1, 1, 0};
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            zeroN[i] = zeroN[i - 1] + zeroN[i - 2];
            oneN[i] = oneN[i - 1] + oneN[i - 2];
        }
        cout << zeroN[n] << ' ' << oneN[n] << '\n';
    }
}