#include <iostream>
#include <queue>
using namespace std;

int N,M;
int map[101] = {0};
bool visit[101];

void BFS(int pos, int cnt){
    queue<pair<int,int>> q;
    q.push({pos,cnt});
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int i = 1; i<7; i++){
            int nPos = tmp.first + i;
            if(nPos == 100) {cout << tmp.second+1; return;}
            else {
                while(map[nPos] != 0) {
                    nPos = map[nPos];
                }
                if(!visit[nPos]){
                    q.push({nPos,tmp.second+1});
                    visit[nPos] = true;
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int x,y;
    for(int i = 0; i<N; i++){ cin >> x >> y; map[x] = y;}
    for(int i = 0; i<M; i++){ cin >> x >> y; map[x] = y;}
    BFS(1, 0);
}

