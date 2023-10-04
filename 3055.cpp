#include <iostream>
#include <queue>
using namespace std;

int N,M;    
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char map[51][51];
bool waterV[51][51], hedgeV[51][51];
queue<pair<int,int>> waterQ, hedgeQ;
int dist[51][51];

void waterRise(){
    int wQsize = waterQ.size();
    while(wQsize--){
        pair<int,int> tmp = waterQ.front();
        waterV[tmp.first][tmp.second] = true;
        waterQ.pop();
        for(int k = 0; k<4; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                if(!waterV[nY][nX] && map[nY][nX] == '.'){
                    map[nY][nX] ='*';
                    waterQ.push({nY,nX});
                    waterV[nY][nX] = true;
                }
            }
        }
    }
}

void moveHedgehog(){
    while(!hedgeQ.empty()){
        waterRise();
        int hQsize = hedgeQ.size();
        while(hQsize--){
            pair<int,int> tmp = hedgeQ.front();
            hedgeQ.pop();
            hedgeV[tmp.first][tmp.second] = true;

            for(int k = 0; k<4; k++){
                int nY = offset[k][0] + tmp.first;
                int nX = offset[k][1] + tmp.second;
                if(nY >= 0 && nY < N && nX >= 0 && nX < M){
                    if(!hedgeV[nY][nX] && map[nY][nX] == '.'){
                        hedgeQ.push({nY,nX});
                        hedgeV[nY][nX] = true;
                        dist[nY][nX] = dist[tmp.first][tmp.second]+1;
                    }
                    else if (map[nY][nX] == 'D') {cout << dist[tmp.first][tmp.second]+1; return;}
                }
            }    
        }
    }
    cout << "KAKTUS";
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

    moveHedgehog();
}