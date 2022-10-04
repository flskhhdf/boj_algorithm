#include "iostream"
#include <ios>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int num1, num2, num3, num4, num5, cnt=0,flag=1;
    int case1= 0;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    while(flag){
        if(num1 > num2){
            int temp = 0;
            temp = num1;
            num1 = num2;
            num2 = temp;
            cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << ' ' << num5 << '\n';
        }
        if (num2 > num3){
            int temp = 0;
            temp = num2;
            num2 = num3;
            num3 = temp;
            cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << ' ' << num5 << '\n';
        }
        if (num3 > num4){
            int temp = 0;
            temp = num3;
            num3 = num4;
            num4 = temp;
            cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << ' ' << num5 << '\n';
        }
        if (num4 > num5){
            int temp = 0;
            temp = num4;
            num4 = num5;
            num5 = temp;
            cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << ' ' << num5 << '\n';
        }
        if(num1 < num2 && num2 < num3 && num3 < num4 && num4 < num5) flag = 0;
    }
}

