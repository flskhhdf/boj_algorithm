#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int i = 0; i<tc; i++){
        int n,gap,max=0;
        cin >> n;
        int num[n];
        for(int j = 0; j<n; j++){
            cin >> num[j];
        }
        sort(num, num+n);
        for(int k = n-1; k>0; k--){
            gap = num[k]-num[k-1];
            if(gap > max) max = gap;
        }
        cout << "Class " << i+1 <<'\n';
        cout << "Max " << num[n-1] << ", " << "Min " << num[0] << ", " << "Largest gap " << max << '\n';
    }
}