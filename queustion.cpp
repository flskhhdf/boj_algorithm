#include "algorithm"
#include "iostream"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, S, min = 100001;
    long long sum = 0, diff = 0, arr[100001] = {0};
    cin >> n >> S;
	
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == S) {
            cout << 1;
            return 0;
        }
        arr[i] += arr[i-1];
    }

	// for(int i = 1; i<=n; i++){
	// 	cout << arr[i] << ' ';
	// }
	// cout << '\n';
	
    int s = 0, e = 1;
    if (arr[n] < S)
        min = 0;
    else {
        while (s < n and e < n) {
            sum = arr[e] - arr[s];
            diff = e - s;
			// cout << "sum : " << sum << '\n';
			if (sum < S) {
                if(min <= diff){
					s++;
                	e = s + 1;
					continue;
				}
				e++;
            }
			else {
                if (diff < min) min = diff;
                if (min == 2) break;
					s++;
					e = s + 1;
            }
            // cout<<e<<' '<<s<<' '<<min<<'\n';
		}
    }
    if (min == 100001) min = 0;
    cout << min;
    return 0;
}