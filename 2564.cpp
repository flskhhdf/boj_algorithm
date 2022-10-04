#include "iostream"
#include "vector"
#include <utility>
using namespace std;

int main(){
	// 1.북 2.남 3.서 4.동
	vector<pair<int, int>> v;
	int n,m,k,dir,store,Dpos,Ddir,sum=0;
	int cwise,uncwise;
	cin >> n >> m >> k;
	
	for(int i = 0; i<k; i++){
		cin >> dir >> store; 
		if(dir == 2) store = 2*n+m-store; // 0,0을 기준으로 얼마나 떨어져있는가 확인
		else if(dir == 3) store = 2*n+2*m-store;
		else if(dir == 4) store = n+store;
		v.push_back({dir,store});
	}

	cin >> Ddir >> Dpos;

	if(Ddir == 2) Dpos = n+m+(n-Dpos); 
	else if(Ddir == 3) Dpos = 2*n+m+(m-Dpos);
	else if(Ddir == 4) Dpos = n+Dpos;

	for(int i = 0; i<v.size(); i++){
		int tmp = abs(Dpos - v[i].second);

		sum += min(2*n+2*m-tmp,tmp);
	}
	cout << sum << '\n';
}