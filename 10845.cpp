#include "iostream"
#include "queue"
#include <queue>
using namespace std;
queue<int> q;

int main(){
    int tc;
    string com;
    int num;
    cin >> tc;
    while(tc--){
        cin >> com;
        if(com == "push") {
            cin >> num;
            q.push(num);
        } 
        else if (com == "pop") {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } 
        else if (com == "front"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (com == "back"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        } 
        else if (com == "size") {
            cout << q.size() << '\n';
        }
        else if (com == "empty"){
            cout << q.empty() << '\n';
        }
    }
}

