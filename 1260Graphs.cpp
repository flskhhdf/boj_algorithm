#include "iostream"
#include "queue"
#include "vector"
#include <algorithm>
#include <cstring>
#include "cstring"
using namespace std;

int n,m,v,from,to;
bool visit[1001];
vector<int> ve[1001];
queue<int> q;

void dfs(int cur){
    cout << cur << ' ';
    visit[cur] = 1;
    for(int i=0; i<ve[cur].size(); i++){
        int next = ve[cur][i];
        if(!visit[next]) dfs(next); 
    }
}


void bfs(int cur){
    while(!q.empty()){
        int cur = q.front(); // 제일 앞에 가져옴
        q.pop(); // 제일 앞에 있는거 지움

        cout << cur << ' ';

        for(int i = 0; i<ve[cur].size(); i++){
            int next = ve[cur][i];
            if(!visit[next]){
                q.push(next);
                visit[next] = 1;
            }
        }
    }
}

int main(){

    cin >> n >> m >> v;

    for(int i = 0; i<m; i++){
        cin >> from >> to;
        ve[from].push_back(to);
        ve[to].push_back(from);
    }
    for(int i = 0; i<=n; i++){
        sort(ve[i].begin(), ve[i].end());
    }
    
   dfs(v);
   cout << '\n';
   memset(visit, 0, sizeof(visit));
   q.push(v);
   visit[v] = 1;
   bfs(v);
}