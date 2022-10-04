#include "iostream"
using namespace std;

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        string s;
        cin >> n >> s;
        for(int i = 0; i<s.length(); i++){
            for(int j = 0; j<n; j++){
                cout << s[i];
            }
        }
        cout << '\n';
    } 
}