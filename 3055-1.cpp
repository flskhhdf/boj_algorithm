#include <iostream>
#include <queue>
using namespace std;

int N,M;    
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int cnt = 0;
string map[51];
bool waterV[51][51], hedgeV[51][51];
queue<pair<int,int>> waterQ, hedgeQ;

int waterRise(){
    int Wcnt = 0;
    while(!waterQ.empty()){
        int wqSize = waterQ.size();
        while(wqSize--){
            pair<int,int> tmp = waterQ.front();
            waterQ.pop();
            waterV[tmp.first][tmp.second] = true;
            for(int k = 0; k<4; k++){
                int nY = offset[k][0] + tmp.first;
                int nX = offset[k][1] + tmp.second;
                if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                    if(!waterV[nY][nX] && map[nY][nX] == '.') {
                        waterQ.push({nY,nX});
                        waterV[nY][nX] = true;
                    }
                    else if (map[nY][nX] == 'D') return Wcnt;
                }
            }
        }
        Wcnt++; 
    }
    return 0;
}

int moveHedgehog(){
    int Hcnt = 0;
    while(!hedgeQ.empty()){
        int hqSize = hedgeQ.size();
        while(hqSize--){
            pair<int,int> tmp = hedgeQ.front();
            hedgeQ.pop();
            hedgeV[tmp.first][tmp.second] = true;
            for(int k = 0; k<4; k++){
                int nY = offset[k][0] + tmp.first;
                int nX = offset[k][1] + tmp.second;
                if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                    if(!hedgeV[nY][nX] && map[nY][nX] == '.') {
                        hedgeQ.push({nY,nX});
                        hedgeV[nY][nX] = true;
                    }
                    else if (map[nY][nX] == 'D') return Hcnt;
                }
            }
        }
        Hcnt++; 
    }
    return 0;
}

int main(){

    cin >> N >> M;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == '*') waterQ.push({i,j});
            else if (map[i][j] == 'S') hedgeQ.push({i,j});
        }
    }

    int waterSpeed =  waterRise();
    int HedgeSpeed =  moveHedgehog();

    if(waterSpeed < HedgeSpeed) cout << HedgeSpeed+1;
    else cout << "KAKTUS";

}