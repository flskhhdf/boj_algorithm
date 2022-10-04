#include "iostream"
using namespace std;

int main(){
    string s;
    string result;
    int cnt=0;

    cin >> s;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == 'X') {
            cnt++;
        }
        if (s[i] == '.' ){
            result += ".";
            if(cnt % 2 != 0)break;
            else cnt  = 0;
        }
        if (cnt == 4){
            result += "AAAA";
            cnt = 0;
        }
        else if(cnt == 2 && s[i+1] != 'X'){
            result += "BB";
            cnt = 0;
            }
        }
    if (cnt % 2 == 1) cout << -1;
    else cout << result;
}