#include "iostream"
#include "algorithm"
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i<n; i++){
        cin >> p[i];
    }
    sort(p,p+n);
    // 1 2 3 3 4
    int sum=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i+1; j++){
            sum += p[j];
        }
    }
    cout << sum;
}

// 1 2 3 3 4
// 1, 1+2, 1+2+3, 1+2+3+3, 1+2+3+3+4
// 1, 3, 6, 9, 13