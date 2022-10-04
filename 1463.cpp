#include "iostream"
#include <algorithm>
#include <limits.h>
using namespace std;
int main(){
    int n,cnt=0;
    cin >> n;
    int arr[1000001] = {0,0,1,1,0};

    // arr[1] = 0 n=1일때
    // arr[2] = 1 n=2일때
    // arr[3] = 1 n=3일때
    // arr[4] = 2
    // arr[5] = 3
    // arr[6] = 2,4
    for(int i = 4; i<=n; i++){
        arr[i] = INT_MAX;
        if(i%3==0) arr[i] = min(arr[i/3]+1, arr[i]);
        if(i%2==0) arr[i] = min(arr[i/2]+1, arr[i]);
        arr[i] = min(arr[i-1]+1, arr[i]);
        // if(i%6==0){
        //     arr[i] = min({arr[i/3]+1 , arr[i/2]+1, arr[i-1]+1});
        // }
        // else if(i%3==0) {
        //     arr[i] = min(arr[i/3]+1, arr[i-1]+1);
        // }
        // else if(i%2==0) {
        //     arr[i] = min(arr[i/2]+1, arr[i-1]+1);
        // }
        // else {
        //     arr[i] = arr[i-1]+1;
        // }
    }
    cout << arr[n];
}