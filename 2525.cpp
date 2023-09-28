#include <iostream>
using namespace std;

int main(){
    int A,B,C,h,m;
    cin >> A >> B >> C;
    m = B + C;
    if(m >= 60) {
        A += m/60;
        B = m%60;
    }
    else B = m;
    if(A>=24) A %= 24;
    cout << A << ' ' << B;
}