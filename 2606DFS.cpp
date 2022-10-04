#include "iostream"
#include "vector"
using namespace std;

int n,m,from,to,cnt;
bool visit[101];
vector<int> ve[101];

void dfs(int cur){
    visit[cur] = 1;
    cnt++;
    for(int i = 0; i<ve[cur].size(); i++){
        int next = ve[cur][i];
        if(!visit[next]) dfs(next);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> from >> to;

        ve[from].push_back(to); // 벡터는 입력받고 바로 만든다
        ve[to].push_back(from);
    }
    dfs(1);
    cout << cnt-1;
}

// 1 2
// 2 1
// 2 3
// 3 2
// 1 5
// 5 1
// 5 2
// 2 5
// 5 6
// 6 5
// 4 7
// 7 4