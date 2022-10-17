#include<iostream>
#include<math.h>

using namespace std;


int main() {
    int a, b, c;

    cin >> a >> b;

    if (a <= b) { cout << 0; return 0;}
    
    for (int i = 0; i < b; i++) {
		c = 0;
		while (pow(2, c + 1) <= a) c++;
		a -= pow(2, c);
		if (a == 0) break;
    }
	if(a) cout << pow(2, c) - a;
	else cout << 0;
    
    return 0;
}