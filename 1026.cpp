#include "iostream"
#include <algorithm>
using namespace std;

int main(){
   int n;
   cin >> n;
   int A[n], B[n];
   for(int i = 0; i<n; i++){
       cin >> A[i];
    }
    for(int i = 0; i<n; i++){
       cin >> B[i];
    }
   sort(A, A+n);
   sort(B, B+n, greater<>());

    int s=0;
    for(int i = 0; i<n; i++){
       s += A[i]*B[i];
    }
    cout << s;
}

