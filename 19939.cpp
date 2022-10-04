#include "iostream"
using namespace std;

int main(){
    int n, k,sum=0;
    cin >> n >> k;
    for(int i = 1; i<=k; i++){
        sum += i;
    }
    n-=sum;

    n < 0 ? cout << -1 : n % k == 0 ? cout << k - 1 : cout << k;

    // if(n<0) cout << -1;
    // else{
    //     n % k == 0 ? cout << k - 1 : cout << k;
    // }
}