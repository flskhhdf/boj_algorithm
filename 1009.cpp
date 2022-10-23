#include "iostream"
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, result = 1;
        cin >> a >> b;
        for (int i = 0; i < b; i++) result = (result * a) % 10;
        if (result == 0) cout << 10 << '\n';
        else cout << result << '\n';
    }
}
