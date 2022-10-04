#include "iostream"
using namespace std;

int main(){
	string word;
	int cnt=0;
	cin >> word;
	for(int i = 0; i<word.length(); i++){
		if(word[i]=='c'){
			if(word[i+1]=='='||word[i+1]=='-') {
				cnt++;
				i++;
			}
			else cnt++;
		}

		else if (word[i]=='d'){
			if(word[i+1]=='z' && word[i+2]=='='){
				cnt++;
				i+=2;
			}
			else if(word[i+1]=='-'){
				cnt++;
				i++;
			}
			else cnt++;
		}

		else if(word[i]=='l'){
			if(word[i+1]=='j'){
				cnt++;
				i++;
			}
			else cnt++;
		}

		else if(word[i]=='n'){
			if(word[i+1]=='j'){
				cnt++;
				i++;
			}
			else cnt++;
		}

		else if(word[i]=='s'){
			if(word[i+1]=='='){
				cnt++;
				i++;
			}
			else cnt++;
		}

		else if(word[i]=='z'){
			if(word[i+1]=='='){
				cnt++;
				i++;
			}
			else cnt++;
		}
		else cnt++;
	}
	cout << cnt;
}