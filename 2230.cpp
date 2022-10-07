#include "iostream"
#include "limits.h"
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, input, min = INT_MAX, left = 0, right = 0, diff;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
	
	while(left < n && right < n){
		diff = abs(v[left] - v[right]);
		if(diff < m) right++;
		else {
			if(diff < min) min = diff;
			left++;
		} 
	}
    cout << min;
}

