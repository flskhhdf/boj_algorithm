#include "iostream"
using namespace std;

int main(){
	string save[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
	int num[3]={0};
	string input[3];
	for(int i = 0; i<3; i++){
		cin >> input[i];
	}
	for(int i = 0; i<3; i++){
		for(int j = 0; j<10; j++){
			if(input[i] == save[j]) num[i] = j;
		}
	}
	int sum = num[0]*10+num[1];
	if(sum == 0) cout << 0;
	else {
		cout << sum;
		for(int i = 0; i<num[2]; i++){
			cout << 0;
		}
	}
}