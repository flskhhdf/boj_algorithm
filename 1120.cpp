#include "iostream"
#include <algorithm>
using namespace std;

int main(){
    int cnt,min=100000;
    string s1, s2;
    cin >> s1 >> s2;
    int diff = s2.length() - s1.length();
    for(int i = 0; i<diff+1; i++){
        cnt = 0;
        for(int j = 0; j<s1.length(); j++){
            if(s1[j] != s2[i+j]) cnt++;
        }
        if(cnt < min) min = cnt;
    }
    cout << min;
}

// s1 koder 
// s2 topcoder

// giorgi 
// igroig