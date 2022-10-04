#include "iostream"
#include "algorithm"
using namespace std;

int main(){
    string n;
    int cnt=1,result=0,dcnt=0,flag=0;
    cin >> n;
    for(int i = 0; i<n.length(); i++){
        if(n[i] == '9') n[i] = '6';
    }
    sort(n.begin(), n.end());
    for(int i = 0; i<n.length(); i++){   
        if(i != (int)n.length()-1){
            if(n[i] == n[i+1]){
                flag = 1;
                if(n[i] == '6'){
                    dcnt++;
                }
                else cnt++;
                if(dcnt % 2 == 0 && dcnt !=0 && dcnt > cnt) {
                    cnt++;
                }
                if(cnt > result){
                    result = cnt;
                }
            }
            else if(n[i] != n[i+1]) cnt = 1;
        }
    }
    if(flag) cout << result;
    else cout << 1;
}