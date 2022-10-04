#include "iostream"
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i<n; i++) cin >> num[i];
    if(n==1) { cout << num[0]*num[0]; return 0;}
    sort(num, num+n);
    cout << num[0]*num[n-1];
}