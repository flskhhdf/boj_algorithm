#include "iostream"
#include <cstdio>
#include <ios>
#include "map"
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    map<string, bool> m;
    string str;
    for(int i = 0; i<n; i++){
        cin >> str;
        if (str == "ENTER") {
            m = map<string, bool>();
            continue;
        }
        if (m.find(str) == m.end()) {
            m.insert({str, true});
            cnt++;
        }
    }
    cout << cnt;
}
