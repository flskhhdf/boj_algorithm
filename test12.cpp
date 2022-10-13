#include "iostream"
#include "cstring"
using namespace std;

int recursion(string s,int l,int r){
	if(l>=r) return 1;
	else if(s[l]!=s[r]) return 0;
	else return recursion(s, l+1, r-1);
}

int isPalindrome(string s){
	return recursion(s, 0, s.length()-1);
}

int main(){
	string S;
	cin>>S;
	cout<<isPalindrome(S);
	return 0;
}