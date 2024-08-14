#include <iostream>
#include <queue>
using namespace std;

int K,W,H;
int map[201][201];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0,-1}};
int hMove[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {1,-2}, {-1, 2}, {2, -1}, {-2, -1}, {-1, -2}};
bool visit[201][201][31];

void BFS(){
    queue<pair<pair<int,int>,pair<int,int>>> q; // y x moveCnt useHmove;
    q.push({{0, 0},{0, 0}});
    visit[0][0][0] = true;

    while(!q.empty()){
        pair<int,int> tmp = q.front().first;
        int cnt = q.front().second.first;
        int skill = q.front().second.second;
        q.pop();

        if(tmp.first == H-1 && tmp.second == W-1){ cout << cnt; return; }

        if(skill < K){
            for(int i = 0; i<8; i++){
                int nY = hMove[i][0] + tmp.first;
                int nX = hMove[i][1] + tmp.second;
                if(nY >= 0 && nY < H && nX >= 0 && nX < W){
                    if(map[nY][nX] == 0 && !visit[nY][nX][skill+1]){
                        visit[nY][nX][skill+1] = true;
                        q.push({{nY, nX},{cnt+1, skill+1}});
                    }
                } 
            }
        }

        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < H && nX >= 0 && nX < W){
                if(map[nY][nX] == 0 && !visit[nY][nX][skill]){
                    visit[nY][nX][skill] = true;
                    q.push({{nY, nX},{cnt+1, skill}});
                }
            } 
        }
    }
    cout << -1;
}

int main(){
    cin >> K;
    cin >> W >> H;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            cin >> map[i][j]; 
        }
    }
    BFS();
}
