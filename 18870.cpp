#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int vSize = v.size();

    for(int i = 0; i<n; i++) { cout << arr[i] << ' ';}
    cout << '\n';
    for(int i = 0; i<vSize; i++) { cout << v[i] << ' ';}
    cout << '\n';
    for(int i = 0; i<n; i++){
        cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << ' ';
    }
}
