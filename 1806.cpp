#include "iostream"
#include <vector>
using namespace std;

int main(){
	int n,s,input,start=0,end=0,sum,min=2147483647,ans=0;
	vector<int> v;
	cin >> n >> s;
	for(int i = 0; i<n; i++){
		cin >> input;
		v.push_back(input);
	}
	sum = v[0];
	while(start < n && end < n){
		if(sum >= s){
			ans = end-start+1;
			if(ans < min) min = ans;
			sum -= v[start++];
		}
		else if (sum < s){
			sum += v[++end]; 
		}
		cout << start << ' ' << end << ' ' << sum <<  '\n';
	}
	if(!ans) cout << 0;
	else cout << min;
}