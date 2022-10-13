#include "iostream"
#include "cmath"
#include "algorithm"
using namespace std;

int main(){
    int n,a[100001]={0},min=2147483647,first=0,second=0;
    cin>>n;
    int s=0,e=n-1,sum=0;
    for(int i=0;i<n;i++){
    	cin>>a[i];        
    }
    sort(a,a+n);
    // min=a[s]+a[e];
    while(s<e){
        sum = a[s]+a[e];
		// cout << sum << ' ';
        if(abs(sum)<min){
			// cout << "check" << '\n';
            first=a[s];
            second=a[e];
            min=abs(sum);
        	cout<<min<<' '<<first<<' '<<second<<'\n';
        }
        if(sum<0) s++;
        else e--;
    }
    return 0;
}