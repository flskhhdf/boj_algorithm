#include <iostream>
#include <queue>
using namespace std;

int N;
int r1,r2,c1,c2;
bool visit[201][201];
int offset[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

void BFS(int r1, int c1){
    queue<pair<pair<int,int>, int>> q;
    q.push({{r1,c1},0});
    visit[r1][c1] = true;

    while(!q.empty()){
        pair<int,int> tmp = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(tmp.first == r2 && tmp.second == c2) {cout << cnt; return;}
        for(int k = 0; k<6; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nY < N && nX >= 0 && nX < N){
                if(!visit[nY][nX]){
                    visit[nY][nX] = true;
                    q.push({{nY,nX}, cnt+1});
                }
            }
        }
    }
    cout << -1;
}

int main(){
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
    BFS(r1,c1);
}