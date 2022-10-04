#include "iostream"
using namespace std;

int main(){
    int a,b,cd,lcm,gcd=0;
    cin >> a >> b;
    for(int i = 1; i<=b; i++){
        if(a%i == 0 && b%i == 0){
            cd = i;
            if(cd > gcd){
                gcd = cd;
            }
        } 
    }
    lcm = (a*b)/gcd;
    cout << gcd << '\n' << lcm;

}