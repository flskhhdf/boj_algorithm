#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int n,m,from,to,cnt;
vector<int> v[101];
queue<int> q;
bool visit[101];

void bfs(int cur){
    visit[cur] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

    for(int i = 0; i<v[cur].size(); i++){
        int next = v[cur][i];
        if(!visit[next]){
            q.push(next);
            visit[next] = 1;
            cnt++;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    q.push(1);
    bfs(1);
    cout << cnt;
}