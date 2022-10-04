#include "iostream"
#include <cstring>
#include <stack>
using namespace std;

stack<char> s;

int main() {
    int tc;
    string barkect;
    cin >> tc;
    while (tc--) {
        bool flag = true;
        s = stack<char>();
        cin >> barkect;
        for (int i = 0; i < (int)barkect.size(); i++) {
            if (barkect[i] == '(') {
                s.push(barkect[i]);
            } else if (barkect[i] == ')') {
                if (s.empty()) {
                    flag = 0;
                    break;
                }
                if (s.top() == '(') { s.pop(); }
            }
            if (s.empty()) flag = 1;
            else flag = 0;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}