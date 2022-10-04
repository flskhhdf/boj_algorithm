#include "iostream"
using namespace std;

int main(){
   int a,b,c,com[10]={0};
   cin >> a >> b >> c;
   int res = a*b*c;
   string strRes = to_string(res);
   for(int i = 0; i<strRes.size(); i++){
      com[strRes[i]-'0']++;
   }
   for(int i = 0; i<10; i++){
      cout << com[i] << '\n';
   }
}