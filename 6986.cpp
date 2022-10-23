#include "iostream"
using namespace std;

int main() {
    long long ans, n, m;
    cin >> n >> m;

    if (m == 0) {
        cout << n - 1;
        return 0;
    }

    if (n == 1 || n == 5) ans = 8 * m - 1 + n;
    else if (n == 2) m % 2 == 0 ? ans = 8 * (m / 2) + 1 : ans = 8 * (m / 2) + 7;
    else if (n == 3) ans = 4 * m - 1 + n;
    else if (n == 4)  m % 2 == 0 ? ans = 8 * (m / 2) + 3 : ans = 8 * (m / 2) + 5;
    
    cout << ans;
}