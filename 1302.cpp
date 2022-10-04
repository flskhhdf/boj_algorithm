#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int n,cnt=0,max=-1,flag;
    cin >> n;
    string s[n];
    for(int i = 0; i<n; i++){
        cin >> s[i];
    }
    if(n==1){
        cout << s[0];
        return 0;
    }
    sort(s,s+n);
    for(int i = 0; i<n; i++){
        s[i] == s[i+1] ? cnt++ : cnt = 0;
        if(cnt > max) {
            max = cnt;
            flag = i;
        }
    }
    cout << s[flag];
}