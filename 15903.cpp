#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    long long sum=0,result=0;
    cin >> n >> m;
    long long a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<m; i++){
        sort(a,a+n);
        sum = a[0]+a[1];
        a[0]=sum;
        a[1]=sum;
    }

    for(int i = 0; i<n; i++){
        result+=a[i];
    }

    cout << result;
}