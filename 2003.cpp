#include "iostream"
using namespace std;

int main() {
    
	int n,m,cnt=0,res,a[10001];
	cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            res += a[j];

            if(res==m) {
                cnt++;
                res = 0;
                break;
            }
        }
        if(res!=0) res=0;
    }   
    cout<< cnt;
}