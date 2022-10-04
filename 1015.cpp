#include "iostream"
using namespace std;

int main(){
    int n,cnt[51]={0};
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(a[i] > a[j]) cnt[i]++;
        }
    }

    for(int i = n-1; i>=0; i--){
        for(int j = i-1; j>=0; j--){
            if(a[i] >= a[j]) cnt[i]++;
        }
    }

    for(int i = 0; i<n; i++){
        cout << cnt[i] << ' ';
    }
}