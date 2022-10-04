#include "iostream"
#include "math.h"
using namespace std;

int main(){
    int w,h;
    cin >> h >> w;
    int r[w];
    int maxL, maxR,ans=0,res=0;

    for(int i = 0; i<w; i++){
        cin >> r[i];
    }

    for(int i = 1; i<w-1; i++){
        maxL=0, maxR=0;
        for(int j = 0; j<i; j++){
            if(r[j] > maxL) maxL = r[j];
        }
        for(int k = w-1; k>i; k--){
            if(r[k] > maxR) maxR = r[k];
        }
        ans=min(maxL,maxR)-r[i]; 
        if(ans>=0) res+=ans;
    }
    cout << res;
}