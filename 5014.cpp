#include <iostream>
#include <queue>
using namespace std;

bool visit[1000001];
queue<pair<int,int>> q;

int main(){
    int F,S,G,U,D,cnt=0;
    cin >> F >> S >> G >> U >> D;
    q.push({S,0});
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();

        if(tmp.first == G) {cout << tmp.second; return 0;}

        if(!visit[tmp.first]){
            visit[tmp.first] = true;
            if(tmp.first + U <= F && tmp.first + U > 0) {q.push({tmp.first+U, tmp.second+1}); }
            if(tmp.first - D <= F && tmp.first - D > 0) {q.push({tmp.first-D, tmp.second+1}); }
        }
    }
    cout << "use the stairs";
}