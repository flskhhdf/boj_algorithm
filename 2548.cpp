#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int n,cur,min=100000,flag;
    cin >> n;
    int num[n],res[n];
    for(int i = 0; i<n; i++){
        cin >> num[i];
        // res[i] = 0;
    }

    sort(num, num+n);

    cout << num[(n-1)/2];

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cur = num[i]-num[j];
    //         if(cur < 0) cur *=-1;
    //         res[i] += cur;
    //     }
    //     if(res[i] < min) {
    //         min = res[i];
    //         flag= num[i];
    //     }
    // }

    // // for(int i = 0; i<n; i++){
    // //     cout << res[i] << '\n';
    // // }

    cout << flag;
}