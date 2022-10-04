#include "iostream"
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    string n;
    cin >> n;
    sort(n.begin(), n.end(), greater<>());

    if(n[n.length()-1] != '0') cout << -1;

    else {
        int temp=0;
        for(int i = 0; i<n.size(); i++){
            temp += n[i];
        }
        if(temp % 3 == 0) cout << n;
        else cout << -1;
    }
}