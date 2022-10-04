#include "iostream"
using namespace std;

int main(){
    int n,k,cnt=0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int sum=0;
    for(int i = n-1; i>=0; i--){
        if(a[i] > k) continue;
        sum += k/a[i];
        k = k%a[i];
    }
    cout << sum;
}