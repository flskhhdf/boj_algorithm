#include "iostream"
#include <ios>
using namespace std;

int main(){
    long long s, n=1;     
    cin >> s;
    while((n*(n+1))/2 <=s){
        n = n+1;
    }
    cout << n-1;
}

// 1 = 1 // 1
// 2 = 1 // 2

// 3 = 2 // 1+2
// 4 = 2 // 1+3
// 5 = 2 // 1+4

// 6 = 3 // 1+2+3
// 7 = 3 // 1+2+4
// 8 = 3 // 1+2+5
// 9 = 3 // 1+2+6

// 10 = 4 // 1+2+3+4 
// 11 = 4 // 1+2+3+5
// 12 = 4 // 1+2+3+6
// 13 = 4 // 1+2+3+7
// 14 = 4 // 1+2+3+8

// 15 = 5 // 1+2+3+4+5