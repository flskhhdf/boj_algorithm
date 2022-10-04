#include "iostream"
#include <stack>
using namespace std;
stack<int> s;


int main(){
    int k,n,size,sum=0;
    cin >> k;
    for(int i = 0; i<k; i++){
        cin >> n;
        if(n == 0) s.pop();
        else s.push(n);
    }
    size = s.size();
    while (s.size()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}
