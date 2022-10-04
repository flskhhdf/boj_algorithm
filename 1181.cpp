#include "iostream"
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if (a.length() == b.length()) {
        return a < b;
    } else {
        return a.length() < b.length();
    }
}

int main(){
    int n;
    string temp = " ";
    cin >> n;
    string s[n];
    for(int i = 0; i<n; i++){
        cin >> s[i];
    }
    sort(s, s+n, compare);

    for(int i = 0; i<n; i++){
        if(temp != s[i]) cout << s[i] << '\n';
        temp = s[i];
    }
    
    // for(int i = 0; i<n; i++){
    //     if(s[i] == s[i+1]) i++;
    //     cout << s[i] << '\n';
    // }
}