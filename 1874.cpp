#include "iostream"
#include "stack"
#include <vector>
using namespace std;

int main(){
	stack<int> s;
	int n,tmp = 0,num,cnt=0;
	bool check = 1;
	vector<char> v;

	s.push(tmp++); 
	
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> num;
		while(s.top() < num){ 
			s.push(tmp++);
			v.push_back('+');
		}
		if(s.top() == num){
			s.pop();
			v.push_back('-');
		}
		else check = 0;
	}

	if(check) for(int i = 0; i<v.size(); i++) cout << v[i] << '\n';
	else cout << "NO";
}