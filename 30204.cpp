#include <iostream>
using namespace std;

int main(){
    int N,X,p;
    int sum = 0;
    cin >> N >> X;
    for(int i = 0; i<N; i++){
        cin >> p;
        sum+=p;
    }
    int ans = (sum % X) == 0 ? 1 : 0;
    cout << ans;
}