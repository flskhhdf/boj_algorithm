#include "iostream"
#include "cstring"
#include <cctype>
using namespace std;

int main(){
    string s1;
	getline(cin, s1);
    int flag = 0;
    for(int i = 0; i < s1.length(); i++){
        if (isupper(s1[i])) {
            if(s1[i] == 'U' && flag == 0) flag++;
            else if(s1[i] == 'C' && flag == 1) flag++;
            else if(s1[i] == 'P' && flag == 2) flag++;
            else if(s1[i] == 'C' && flag == 3) flag++;
            if(flag == 4) break;
        }
    }
    if(flag == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";
} // 응 돼