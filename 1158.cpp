#include "iostream"
#include <ios>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,cnt=1,idx=0,idxcnt=0,arr[5000],ans[5000],delcnt=0;;
	cin >> n >> k;
	for(int i = 0; i<n; i++){
		arr[i] = i+1;
	}
	for(int i = 0; i<n; i++){
		while(delcnt!=n){
			
			if(idxcnt == n) idxcnt = 0;
			
			else if(arr[idxcnt]==0){
				idxcnt++;
				continue;
			}
			
			else if(cnt % k == 0){
				ans[idx] = arr[idxcnt]; 
				arr[idxcnt] = 0;
				idx++;
				cnt++;
				idxcnt++;
				delcnt++;
				break;
			}
			
			else {
				cnt++;
				idxcnt++;
			}
		}
	}
	cout << '<';
	for(int i = 0; i<n; i++){
		if(i==n-1) cout << ans[i];
		else cout << ans[i] << ", ";
	}
	cout << '>';
}