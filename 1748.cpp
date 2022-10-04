#include "iostream"
#include <ios>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    
    ios_base::sync_with_stdio(0);
    int n,cnt=0;
    cin >> n;
    if(n<10){
        cout << n;
        return 0;
    }
    
    for(int i = 1; i<=n; i*=10){
        cnt += n-i+1;
    }

    cout << cnt;
}