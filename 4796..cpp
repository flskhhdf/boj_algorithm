#include "iostream"
using namespace std;

int main(){
    int l,p,v,i=0;
    while(1){
        i++;
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) break;
        if(l>(v%p)){
            cout << "Case "<< i << ": " << l*(v/p)+(v%p) << '\n';
        }
        else cout << "Case "<< i << ": " << l*(v/p)+l << '\n'; 

    }
}

// case1 = 4+2
// case1 = 15


