#include "iostream"
#include "algorithm"
#include <functional>
using namespace std;

int main(){
    int n,sum=0;
    cin >> n;
    int t[n];
    for(int i = 0; i<n; i++){
        cin >> t[i];
    }
    sort(t,t+n,greater<>());
    for(int i =0;i<n;i++){
        if(t[i] > i) sum += t[i]-i;
    }
    cout << sum;
}