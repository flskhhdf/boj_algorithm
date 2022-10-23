#include <iostream>
using namespace std;

int main() {
    int n, score, p;
    int rank[100];
    cin >> n >> score >> p;

    for (int i = 0; i < n; i++) {
        cin >> rank[i];
    }

    int cnt = 0;
    int cr = 1;
    for (int i = 0; i < n; i++) {
        if (score < rank[i]) cr += 1;
        else if (score == rank[i]) cr = cr;
        else break;
        cnt++;
    }

    if (cnt == p) cr = -1;
    if (n == 0) cr = 1;

    cout << cr;
}