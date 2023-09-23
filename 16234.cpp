#include <iostream>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;

int map[51][51];
bool visit[51][51];
int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};   
int n,L,R;
int sum = 0, day = 0;
bool flag = true; 

queue<pair<int,int>> q;
vector<pair<int,int>> v;

void BFS(pair<int,int> pos){
    q.push(pos);
    visit[pos.first][pos.second] = true;

    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();

        for(int k = 0; k<4; k++){
            int nY = tmp.first + offset[k][0];
            int nX = tmp.second + offset[k][1];
            if(nY >= 0 && nX >= 0 && nY < n && nX < n){
                int diff = abs(map[nY][nX] - map[tmp.first][tmp.second]);
                if(!visit[nY][nX] && diff <= R && diff >= L){
                    q.push({nY,nX});
                    visit[nY][nX] = true;
                
                    v.push_back({nY,nX});
                    sum += map[nY][nX];
                }
            }
        }
    }
}

int main(){
    cin >> n >> L >> R;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> map[i][j];
        }
    }

    while(flag){
        flag = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!visit[i][j]){
                    v.clear();
                    v.push_back({i,j});
                    sum = map[i][j];
                    BFS({i,j});
                }

                if(v.size() > 1){
                    flag = true;
                    for(int k = 0; k<v.size(); k++){
                        map[v[k].first][v[k].second] = sum/v.size();
                    }
                }
            }
        }
        if(flag) day++;
        memset(visit, false, sizeof(visit));
    }
    cout << day;
}