#include "iostream"
using namespace std;

int ret(int a){
	return a++;
}

int main(){
	int a = 10;
	cout << ret(a);
}