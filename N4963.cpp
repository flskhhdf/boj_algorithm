#include "iostream"
#include <queue>
#include <vector>
using namespace std;
vector<int> v[2500];
bool visit[2500];
queue<int> q;

int BFS(int cur){
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i<v[cur].size(); i++){
            if(v[cur][i] == 0) return 0;
            int next = v[cur][i];
            if(!visit[next]){
                q.push(next);
                visit[next] = 1;
            }
        }
    }
    return 1;
}

int main(){
    int w,h,map,cnt=0;
    cin >> h >> w >> map;
    if(w == 0 && h == 0) return 0;

    for(int i = 0; i<w; i++){
        for(int j = 0; j<h; j++){
            cin >> map;
        }
        if(map == 1) v[i].push_back(1);
    }
   

    for(int i = 1; i<=w; i++){
        if(!visit[i]){
            int res = BFS(i);
            if(res != 0) cnt++;
        }
    }
    cout << cnt;

}