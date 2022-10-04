#include "iostream"
#include <ios>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long arr[90] = {1,1,2,0};
    int n;
    cin >> n;
    for(int i = 3; i<n; i++){
        arr[i] = arr[i-1] + arr[i-2]; 
    }
    cout << arr[n-1];
}