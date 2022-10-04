#include "iostream"
#include <cstddef>
#include <ios>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n,wcnt=0,bcnt=0;
		string cur,goal,temp;
		cin >> n >> cur >> goal;
		for(int i = 0; i<n; i++){
			if(cur[i] != goal[i]){
				if(cur[i] == 'W') wcnt++;
				else bcnt++;
			}
		}
		cout << max(wcnt,bcnt) << '\n';
	}
}