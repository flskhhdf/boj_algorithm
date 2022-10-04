#include "iostream"
#include "algorithm"
#include <algorithm>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    int num[10];
    while(tc--){
        for(int i = 0; i<10; i++){
            cin >> num[i];
        }
        sort(num, num+10);
        cout << num[7] << '\n';
    }
}