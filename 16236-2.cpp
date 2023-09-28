#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;


struct fish{
    int size;
    int dist;
    int y;
    int x;
};

// 비교 함수 정의
bool compareFish(const fish& a, const fish& b) {
    if (a.size != b.size) {
        return a.size < b.size; // size 오름차순
    }
    if (a.dist != b.dist) {
        return a.dist < b.dist; // dist 오름차순
    }
    if (a.y != b.y) {
        return a.y < b.y; // y 오름차순
    }
    return a.x < b.x; // x 오름차순
}


int N;
int map[21][21];
int sharkSize = 2;
int eatCnt = 0, res = 0, idx = 0;
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visit[21][21];
bool isEat = false;
bool isStop = false;
int curX,curY;
vector<pair<int,pair<int,int>>> v;
queue<pair<pair<int,int>, int>> q;

queue<fish> vf;

void setDist(int y,int x){

}

void BFS(int y, int x){
    int eatTime;
    q.push({{y,x},0});
    while(!q.empty()){
        pair<int,int> tmp = q.front().first;
        visit[tmp.first][tmp.second] = true;
        int cnt = q.front().second;
        q.pop();
        for(int k = 0; k<4; k++){
            int nY = offset[k][0] + tmp.first;
            int nX = offset[k][1] + tmp.second;
            if(nY >= 0 && nY < N && nX >= 0 && nX < N && !visit[nY][nX]){
                if(map[nY][nX] <= sharkSize) { // 먹거나 이동 가능한 상태
                    //현재 물고기의 위치에서 벡터 값 들의 위치 변경해주기
                    if(!isEat && map[nY][nX] < sharkSize && nY == vf[idx].y && nX == vf[idx].x){ // 먹을수 있는데 위치가 왼쪽 위인것 우선  
                        map[nY][nX] = 0;
                        curX = nX;
                        curY = nY;
                        isEat = true;
                        idx++;
                        eatTime = cnt+1;
                        res += eatTime;
                        for(int i = 0; i<N; i++){
                            for(int j = 0; j<N; j++){
                                cout << map[i][j] << ' ';
                            }
                            cout << '\n';
                        }
                        cout << "=======================\n";
                    }
                    else {
                        q.push({{nY,nX}, cnt+1});
                        visit[nY][nX] = true;   
                    }
                }
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
                if(map[i][j] == 9){
                    curX = j;
                    curY = i;
                    map[i][j] = 0;
                }
                else {
                    vf.push({map[i][j],0,i,j});
                }
            }
        }
    }

    while(!isStop){        
        memset(visit,0,sizeof(visit));
        setDist(curX,curY);
        BFS(curY, curX);
        if(isEat){
            isEat = false;
            eatCnt++;
            if(eatCnt == sharkSize) { sharkSize++; eatCnt = 0; }
        }
        else {
            isStop = true;
        }
    }
    cout << res;
}

