#include "iostream"
#include <ios>
#include <sys/types.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,bcnt=1,bmax=1,scnt=1,smax=1;
	cin >> n;
	int num[n];
	for(int i = 0; i<n; i++){
		cin >> num[i];
	}

	for(int i = 0; i<n-1; i++){
		if(num[i] <= num[i+1]) {
			bcnt++;
			if(bmax < bcnt) bmax = bcnt;
		}
		else bcnt=1;
	}

	for(int i = 0; i<n-1; i++){
		if(num[i] >= num[i+1]) {
			scnt++;
			if(smax < scnt) smax = scnt;
		}
		else scnt=1;
	}

	cout << max(smax, bmax);
}