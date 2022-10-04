#include "iostream"
#include "math.h"
using namespace std;

int main(){
	int n,m,v;
	double a,b,ans;
	cin >> n >> m >> v;
	a = v-m;
	b = n-m;
	ans = a/b;
	cout.precision(0);
	cout << fixed << ceil(ans);
}