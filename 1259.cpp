#include "iostream"
#include <string>
using namespace std;

int IsPalin(string n){
    for(int i = 0; i<n.length()/2; i++){
        if(n[i] != n[n.length()-i-1]){
            return 0;
        }  
    }
    return 1;
}


int main(){
    string num;
    while(1){
        cin >> num;
        if(num == "0") return 0;
        if(IsPalin(num)==1) cout << "yes\n";
        else cout << "no\n";
    }
}