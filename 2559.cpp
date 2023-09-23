#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k,m,res = 0, sum;
    vector<int> v;

    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> m;
        v.push_back(m);
    }

    for(int i = 0; i<n-k+1; i++){
        sum = 0;
        for(int j = i; j<i+k; j++){
            sum += v[j];
        }
        res = max(res, sum);
    }
    cout << res << '\n';
}  