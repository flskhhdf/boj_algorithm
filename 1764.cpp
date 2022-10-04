#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
int main(){
    int n,m,cnt=0;
    cin >> n >> m;
    string s1[n+m];
    for(int i = 0; i<n+m; i++){
        cin >> s1[i];
    }
    sort(s1, s1+n+m);
    for(int i = 0; i<n+m-1; i++){
        if(s1[i]==s1[i+1]) {
            v.insert(v.begin()+cnt,s1[i]);
            cnt++;
        }        
    }
    cout << cnt << '\n';
    for(int i = 0; i<cnt; i++){
        cout << v.at(i) << '\n';
    }

    // for(int i = 0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(s1[i]==s2[j]){
    //             v.insert(v.begin()+cnt,s1[i]);
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt << '\n';
    // for(int i = cnt-1; i>=0; i--){
    //     cout << v.at(i) << '\n';
    // }
}