#include "iostream"
using namespace std;

int main(){
    int n,cnt=0;
    cin >> n;
    int x,y,z;
    for(int i = 1; i<=n; i++){
        if(i < 100) cnt++;
        
        else if (i<1000){
            x = i/100;
            y = (i%100)/10;
            z = i%10;
            if(x-y == y-z) cnt++;
        }
    }
    cout << cnt;
}
