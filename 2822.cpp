#include "iostream"
#include <algorithm>
#include <functional>
using namespace std;


int main(){
	pair<int, int> p[8];
	int num[8],score[8],sum=0;
	for(int i = 0; i<8; i++){
		cin >> num[i];
		p[i].first = num[i];
		p[i].second = i+1;
	}
	sort(p,p+8);
	for(int i = 3; i<8; i++){
		sum+=p[i].first;
		score[i] = p[i].second;
	}
	cout << sum << '\n';
	sort(score+3,score+8);
	for(int i = 3; i<8; i++){
		cout << score[i] << ' ';
	}
}