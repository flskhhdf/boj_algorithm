#include "iostream"
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n],y[n];
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i<n; i++){
        int cnt=1;
        for(int j = 0; j<n; j++){
            if(x[i] < x[j] && y[i] < y[j]){
                cnt++;
            }
        }
        cout << cnt <<' ';
    }
}

// 5
// 55 185
// 58 183
// 88 186
// 60 175
// 46 155

//------------

// 55 185
// 55 185

// 55 185
// 58 183

// 55 185
// 88 186

// 55 185
// 60 175

// 55 185
// 46 155