#include <iostream>
#include <algorithm> //utility 포함, vector도 마찬가지
#include "ios"
using namespace std;

const int LIMIT=1000001;
bool PrimeArray[LIMIT];

void Eratos(int m, int n) {
    if (n <= 1) return;

    for (int i = m; i <= n; i++) {
        if(i==1) PrimeArray[i]= false;
        else PrimeArray[i] = true;
    }

    for (int i = 2; i * i <= n; i++) {
        if (PrimeArray[i]) {
            for (int j = i * i; j <= n; j += i) {
                PrimeArray[j] = false;
            }
        }
    }

	for(int i = 0; i<n; i++){
		cout << i << ' ' <<PrimeArray[i] << '\n';
	}

    for (int i = m; i <= n; i++)    {
        if (PrimeArray[i]) cout << i<<'\n';
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    Eratos(m, n);
}