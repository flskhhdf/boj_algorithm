#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int n,max=0;
    cin >> n;
    int t[n];
    for(int i =0; i<n; i++){
        cin >> t[i];
    }
    sort(t,t+n);
    for(int i = 0; i<n; i++){
        t[i] -= i;
        if(t[i] > max) max = t[i];
    }
    cout << max+n+1;
}