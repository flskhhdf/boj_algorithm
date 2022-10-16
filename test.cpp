#include "iostream"
using namespace std;

int& funcTow(int var){
	var++;
	int *tmp = &var;
	return *tmp;
}

int main(){

	int n = 10;
	int ref = funcTow(n);

	cout << ref;
}


