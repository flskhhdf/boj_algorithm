#include "iostream"
#include <algorithm>
#include <ios>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    int num[n];
    for(int i = 0; i<n; i++){
        cin >> num[i];
    }
    sort(num,num+n);
    cout << num[k-1];
}