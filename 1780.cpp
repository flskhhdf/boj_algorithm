#include <iostream>
using namespace std;

int paper[2200][2200];
int minu = 0, zero = 0, one = 0;

void DFS(int y, int x, int size){
    bool check = true;

    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            if (paper[i][j] != paper[y][x]){
                check = false;
                break;
            }
        }
        if(!check) break;
    }

    if(!check){
        DFS(y, x, size/3);
        DFS(y, x+size/3, size/3);
        DFS(y, x+size/3+size/3, size/3);
        DFS(y+size/3, x, size/3);
        DFS(y+size/3, x+size/3, size/3);
        DFS(y+size/3, x+size/3+size/3, size/3);
        DFS(y+size/3+size/3, x, size/3);
        DFS(y+size/3+size/3, x+size/3, size/3);
        DFS(y+size/3+size/3, x+size/3+size/3, size/3);
    }
    else{
        if(paper[y][x] == -1) minu++;
        else if (paper[y][x] == 0) zero++;
        else one++;
    }
}

int main(){

    int n;

    cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }

    DFS(0, 0, n);

    cout << minu << '\n' << zero << '\n' << one << '\n';
}