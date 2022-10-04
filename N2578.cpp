#include "iostream"
using namespace std;

int main(){
    int bingo[5][5];
    int n;
    int cnt=0;


    for(int i = 0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> bingo[i][j];
        }
    }

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(bingo[i][j] == n) bingo[i][j] = 0;
        

        }
    }
}