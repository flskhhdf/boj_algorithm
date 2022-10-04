#include "iostream"
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){		
		long long int n,kong[68]={1,1,2,4,0};
		cin >> n;

		for(int i = 4; i<68; i++){
			for(int j = 0; j<4; j++){
				kong[i] = kong[i-1] + kong[i-2] + kong[i-3] + kong[i-4];
			}
		}
		cout << kong[n] << '\n';
	}
}
