#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int m,n;
    cin >> n >> m;
    int p[m],q[m];
    int minP = 1000, minQ = 1000;
    for(int i = 0; i<m; i++){
        cin >> p[i] >> q[i];
        if(p[i] < minP){
            minP = p[i];
        }
        if(q[i] < minQ){
            minQ = q[i];
        }
    }
    if(minQ*6 < minP) {
        cout << minQ*n;
    }
    else {
        if(((n/6)*minP+(n%6)*minQ) > ((n/6)+1)*minP){
            cout << ((n/6)+1)*minP;
        }
        else cout << (n/6)*minP+(n%6)*minQ;
    }
}