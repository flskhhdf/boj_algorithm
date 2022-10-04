#include "iostream"
#include "math.h"
#include <vector>
using namespace std;

int visit[1000000];
int p;

void DFS(int input, int p){
	visit[input]++;
	if(visit[input] == 3) return;
	int sum=0;
	while(input>0){
		sum += pow(input%10,p);
		input /= 10;
	}
	DFS(sum, p);
}


int main(){
	int a,cnt=0;
	cin >> a >> p;
	DFS(a, p);
	for(int i = 0; i<1000000; i++){
		if(visit[i] == 1) cnt++;
	}
	cout << cnt;
}