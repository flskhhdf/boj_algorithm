#include "iostream"
using namespace std;

int main(){
    int n,a,b,c,cnt=0;
    cin >> n;
    int temp=n;
    while(1){
        a = temp/10;
        b = temp%10;
        c = (a+b)%10;
        temp = (b*10)+c;
        cnt++;
        if(temp==n) break;
    }
    cout << cnt;
}
