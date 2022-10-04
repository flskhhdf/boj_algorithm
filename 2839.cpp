#include "stdio.h"
#include "iostream"
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	while(tc--){		
		int N,sum=0,a;
		scanf("%d", &N);
		a = N / 5;
		if (N % 5 == 0) sum = a;
		else if(N%5==1) {
			if (a == 0) sum = -1;
			else sum = a + 1;
		}
		else if (N % 5 == 2){
			if (a < 2) sum = -1;
			else sum = a + 1;
		}
		else if (N % 5 == 3){
			sum = a + 1;
		}
		else if (N % 5 == 4){
			if (a == 0) sum=-1;
			else sum = a + 2;
		}
		printf("%d\n", sum);
	}
}