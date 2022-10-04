#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    int num1[500001], num2[500001];
    int idx[500001]={0};

    cin>> n;
    for(int i = 0; i<n; i++){
        cin >> num1[i];
    }

    sort(num1, num1 + n);

    cin >> m;
    for(int i = 0; i<m; i++){
        cin >> num2[i];
    }
    
    for(int j = 0; j<m; j++){
        if(binary_search(num1,num1+n,num2[j])) idx[j] = 1;
    }

    for(int i = 0; i<m; i++){
        cout << idx[i] << ' ';   
    }
}