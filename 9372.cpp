#include "iostream"
#include "vector"
#include "cstring"
using namespace std;

int n,m,from,to,cnt;
vector<int> v[1001];
int visit[1001];

void dfs(int cur){
    cnt++;
    visit[cur] = 1;
    for(int i = 0; i<v[cur].size(); i++){
        int next = v[cur][i];
        if(!visit[next]) dfs(next);    
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i = 1; i<=n; i++){ // vector clear
            v[i].clear();
        }
        memset(visit, 0, sizeof(visit)); // memset
        cnt = 0; // qudtls
        for(int i = 0; i<m; i++){
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }  
        dfs(from);
        cout << cnt-1 <<'\n';
    }
}