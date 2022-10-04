#include "iostream"
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[1000001] = {0,1,2,0};
    for(int i = 3; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 15746;
    }
    cout << arr[n] << '\n';
}



