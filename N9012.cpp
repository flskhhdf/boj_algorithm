#include <iostream>
#include <stack>
#include <type_traits>
using namespace std;

bool Match(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        stack<int> stack;
        char c;
        while ((c = getchar()) != '\n') {
            if (c == '(' || c == '[' || c == '{') {
                stack.push((int)c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stack.empty())
                    break;
                else if (!Match((char)stack.top(), c))
                    break;
                stack.pop();
            }
        }
        if (stack.empty() && c == '\n')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}