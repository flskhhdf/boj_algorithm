#include "iostream"
#include "math.h"
using namespace std;

int main(){
    const int LIMIT = 1000001;
    bool b[LIMIT] = {1,1,0};
    int n,m,cnt=0;
    cin >> n >> m;
    int sqrtlimit = (int)sqrt((double)LIMIT);
    for(int i = 2; i<=sqrtlimit; i++){
        if(!b[i]){
            for(int j = i*i; j<LIMIT; j=i+j){
                b[j] = 1;
            }
        }
    }

    for(int i = n; i<=m; i++){
        if(!b[i]) cout << i << '\n';
    }
    
}