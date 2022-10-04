#include "iostream"
using namespace std;

int main(){
    int n[10];
    int max=0;
    int min=100000000;
    for(int i = 0; i<10; i++){
        cin >> n[i];
        if(n[i] > max) max = n[i];
        if(n[i] < min) min = n[i];
        cout << max << ' '; 
    }
}