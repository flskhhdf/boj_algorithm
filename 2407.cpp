#include "iostream"
#include <ios>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long n, m, result1 = 1, result2 = 1, result;
    cin >> n >> m;
    if (m == n)
        cout << 1 << '\n';
    else {
        if (m > n / 2) m = n - m;
        for (int i = 0; i < m; i++) {
            result1 *= n - i;
            result2 *= m - i;
            result = result1 / result2;
        }
        cout << result << '\n';
    }
}