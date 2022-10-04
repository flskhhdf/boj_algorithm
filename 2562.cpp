#include "iostream"
using namespace std;

int main(){
    int n,max=0,idx;
    for(int i =0; i<9; i++){
        cin >> n;
        if(n>max){
            max=  n;
            idx = 1+i;

        }
    }
    cout << max << '\n' << idx;
}