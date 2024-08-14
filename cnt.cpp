#include <iostream>
using namespace std;

int main(){
    string input = "abcdebdbecbcdbbbaaaaaabcbdbccccdaaaaaeaaa";
    int a=0,b=0,c=0,d=0,e=0;
    for(int i = 0; i<input.length(); i++){
        if(input[i] == 'a') a++;
        else if(input[i] == 'b') b++;
        else if(input[i] == 'c') c++;
        else if(input[i] == 'd') d++;
        else if(input[i] == 'e') e++;
    }
    cout << a << ' ' << b << ' '<< c << ' '<< d << ' '<< e; 
}