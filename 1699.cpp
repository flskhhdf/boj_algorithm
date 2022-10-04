#include "iostream"
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n[100001]={0,1,2,3,1,0};
    int num,cur,root,idx,cnt[100001];
    cin >> num;

    for(int i = 5; i<=num; i++){
        idx = 0;
        root = sqrt(i);
        for(int j = 1; j<=root; j++){
            cur = j*j;
            if(cur <= i) cnt[idx] = n[i-cur]+1;
            idx++;
        }
        sort(cnt, cnt+idx);
        n[i] = cnt[0];
        for(int k = 0; k<idx; k++){
            cnt[idx] = 0;
        }
    }
    cout << n[num];
}