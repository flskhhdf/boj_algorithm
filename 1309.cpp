#include "iostream"
#include <ios>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    int yeah[100001] = {0, 3, 7, 0};
    cin >> n;
    for(int i = 3; i<=n; i++){
        yeah[i] = (yeah[i-1]*2+yeah[i-2])%9901;
    }

    cout << yeah[n] << "\n";
}