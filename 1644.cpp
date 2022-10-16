#include "iostream"
#include "math.h"
#include <vector>
using namespace std;
#define LIMIT 4000000

int sqrtlimit = (int)sqrt((double)LIMIT);
bool b[LIMIT] = {1,1,0};
vector<int> v;
int n,cnt=0;

int main(){
    
	cin >> n;
	if(n == 1) {cout << 0; return 0;}
	
    for(int i = 2; i<=sqrtlimit; i++){
        if(!b[i]){
            for(int j = i*i; j<LIMIT; j=i+j){
                b[j] = 1;
            }
        }
    }

    for(int i = 0; i<=n; i++){
        if(!b[i]) v.push_back(i);
    }

	int len = v.size();

	if(len == 1) {cout << 1; return 0;}


	int start=0,end=0,sum = v[0];

	while(start <= end && end < len){

		if(sum < n){
			sum += v[++end];
		}

		else if(sum >= n){
			sum -= v[start++];
		}

		if (sum == n) {
			cnt++;
		}

		cout << start << ' ' << end << '\n';
	}
	cout << cnt;
}