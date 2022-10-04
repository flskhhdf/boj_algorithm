#include "iostream"
#include "cstring"
#include <cstring>
#include <ios>
using namespace std;

int main(){
    int n,m,cnt=0;
    int blind[5] = {0};
    cin >> m >> n;
    string s[5*m+1];
    for(int i = 0; i<5*m+1; i++){
        cin >> s[i];
    }
    for(int i = 1; i < 5*m+1; i+=5){
        for(int j = 1; j < 5*n+1; j+=5){
            cnt=0;
            // cout << s[i][j];
            for (int k = 0; k < 4; k++) {
                if (s[i+k][j] == '*') cnt++;
            }
            blind[cnt]++;
        }
        // cout << '\n';
    }
    for(int i = 0; i<5; i++){
        cout << blind[i] << ' ';
    }
}
