#include "iostream"
#include "cmath"
#include <ios>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int LIMIT = 1000001;
    bool visit[LIMIT] = {1,1,0};
	int a,b,tmp,pf[LIMIT] = {0},cnt=0;
	
	cin >> a >> b;
	
	for(int i = 2; i<100001; i++){
		if(!visit[i]){
			for(int j = i*2; j <= b; j+=i){
				visit[j] = 1;
				tmp = j;
				while(tmp%i==0){
					tmp /= i;
					pf[j]++;
				}
			}
		}
	}
	for(int i = a; i<=b; i++) if(!visit[pf[i]]) cnt++;
	cout << cnt;
}