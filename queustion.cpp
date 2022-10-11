#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long sum = 0, min = 3100000001, tmp,min1;
    vector<long long>v, k;
    cin >> n;
    int left = 0, right = n - 1, r1 = 0, r2 = 0, r3 = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    while (left<right) {
        sum = v[left] + v[right];
        if (abs(sum) < min) {
            min = abs(sum);
            r1 = v[left];
            r2 = v[right];
        }
        else if (sum < 0) left++;
        else right--;
    }
	cout << r1 << ' ' << r2 <<'\n';
	min1 = min;
    k.push_back(r1);
    k.push_back(r2);
    min = 300000001;
    for (int i = 0; i < n; i++) {
        tmp = min1;
        if (v[i] == r1 || v[i] == r2) continue;
        else {
            tmp += v[i];
            if (abs(tmp) < min) {
                min = abs(tmp);
                r3 = v[i];
            }
            if (min == 0) break;
        }
    }
    k.push_back(r3);
    sort(k.begin(), k.end());
	// cout << min;
    cout << k[0] << " " << k[1] << " " << k[2];
}