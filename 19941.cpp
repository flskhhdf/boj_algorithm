#include "iostream"
using namespace std;

int main(){
    int n,k,cnt=0;
    string s;
    cin >> n >> k >> s;
    for(int i=0; i<n-1; i++){
        if(s[i] != ' '){
            for(int j = 1; j<=k; j++){
                if(s[i] == 'H' && s[i+j] == 'P') {
                    cnt++;
                    s[i+j] = ' ';
                    break;
                }
                else if (s[i] == 'P' && s[i+j] == 'H') {
                    cnt++;
                    s[i+j] = ' ';
                    break;
                }
            }
        }
    }
    // cout << s << '\n';
    cout << cnt;
}

// cout << cnt;

// HH H P H P PPP P P P
// HHPHPPHHPPHPPPHPHPHP