#include "iostream"
using namespace std;

int main(){
    int n,cd,cur,gcd;
    cin >> n >> cur;
    int num[n-1];
    for (int i = 0; i<n-1; i++) {
        cin >> num[i];
    }
    
    for(int i = 0; i<n-1; i++){
        gcd=0;
        for(int j = 1; j<=cur; j++){
            if(num[i]%j==0 && cur % j == 0){
                cd=j;
                if(cd>gcd) gcd = cd;
                else gcd = 1;
            }
        }
        // cout << gcd << '\n';
        cout << cur/gcd << '/' << num[i]/gcd << '\n'; 
    }
}