#include "iostream"
using namespace std;

int main(){
    int n,flag=0;
    cin >> n;
    int cnt = n;
    string s[101];
    for(int i = 0; i<n ;i++){
        cin >> s[i];
    }
    for(int i = 0; i<n; i++){
        flag=0;
        for(int j = 0; j<s[i].length(); j++){
            for(int k = j + 1; k<s[i].length(); k++){
                if(s[i][j] == s[i][k]){
                    if(j+1 == k) break;
                    else {
                        flag=1;
                        break;
                        }
                }
            }
        }
        if(flag) cnt--;
    }
    cout << cnt;
}