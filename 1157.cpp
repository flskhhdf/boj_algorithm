#include "iostream"
using namespace std;

int main(){
	string input;
	int visit[26]={0},tmp,max=0,cnt=0,flag;

	cin >> input;

	for(int i = 0; i<input.length(); i++){
		if(input[i] < 97) visit[input[i]-65]++;
		else visit[input[i]-97]++;
	}


	for(int i = 0; i<26; i++){
		if(visit[i] > max) {
			max = visit[i];
			flag = i;
		}
	}

	for(int i = 0; i<26; i++){
		if(visit[i] == max) cnt++;
	}

	if(cnt > 1) cout << "?";
	else cout << (char)(flag+65);
}