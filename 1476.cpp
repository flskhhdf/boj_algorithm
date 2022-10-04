#include "iostream"
#include <ios>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int e,s,m,cnt=0;
    int ecnt=0,scnt=0,mcnt=0;
    cin >> e >> s >> m;
    while(1){
        cnt++;
        if(++ecnt == 16) ecnt = 1;
        if(++scnt == 29) scnt = 1;
        if(++mcnt == 20) mcnt = 1;
        // cout << cnt << ' ' << ecnt << ' ' << scnt << ' ' << mcnt << '\n';
        if(ecnt == e && scnt == s && mcnt == m){
            cout << cnt;
            break;
        }
    }
}