#include "iostream"
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;

int main(){
    int n, m, k;
    cin >> n >> m;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> k;
        arr[i] = k;
        q.push(k);
    }

}