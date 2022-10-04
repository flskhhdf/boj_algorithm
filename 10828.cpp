#include "iostream"
#include "stack"
#include <stack>
using namespace std;
stack<int> s;
int main(){
    int tc;
    cin >> tc;
    string com;
    int num;
    while(tc--){
        cin >> com;
        if(com == "push"){
            cin >> num;
            s.push(num);
        }
        else if (com == "pop"){
            if(s.empty()) cout << -1 <<'\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }  
        }
        else if (com == "size"){
            cout << s.size() << '\n';
        }
        else if (com == "empty"){
            cout << s.empty() << '\n';
        }
        else if (com == "top"){
            if(s.empty()) cout << -1 <<'\n';
            else cout << s.top() << '\n';
        }
    }
}
