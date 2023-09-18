#include "iostream"
using namespace std;

int white, blue, paper[128][128];

void DFS(int y, int x, int size){
    int check = paper[y][x];

    for(int i = y; i<y+size; i++){
        for(int j = x; j<x+size; j++){
            if(check != paper[i][j]){ check = 2; }
            if(check == 2){
                // 왼쪽 위
                DFS(y, x,size/2);
                // 오른쪽 위
                DFS(y, x+size/2, size/2);
                // 왼쪽 아래
                DFS(y+size/2, x, size/2);
                // 오른쪽 아래
                DFS(y+size/2, x+size/2, size/2);
                return;
            }
        }
    }
    if(check == 1) blue++;
    else white++;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> paper[i][j];
        }
    }

    DFS(0, 0, n);
    cout << white << '\n' << blue << '\n';

}