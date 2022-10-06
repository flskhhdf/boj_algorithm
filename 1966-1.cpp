#include "iostream"
#include <algorithm>
#include <queue>
using namespace std;

bool comp(int a, int b) { return a>b; }

int main(){
	queue<int> q;
	int n,m,file,impt[100],cnt=0,tmp=0;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> impt[i];
		q.push(impt[i]);
		if(i==m-1) file = impt[i];
	}

	for(int i = 0; i<n; i++){
		if(i <= m && impt[i] == file) tmp++;
		if(impt[i] > file) cnt++;
	}

	sort(impt, impt + n, comp);


}