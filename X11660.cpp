#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[1025][1025];

int main(){

    cout << "hello world";    
    int n,m;
    int x1,x2,y1,y2;
    int offset[4][2] = {{1, 0},{0 ,1},{-1, 0},{0, -1}};

    queue<pair<int,int>> q;
    vector<pair<pair<int ,int>, pair<int ,int>>> v;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    

    for(int i = 0; i<m; i++){
        int sum = 0;
        q.push(v[i].first);
        while(!q.empty()){
            pair<int,int> tmp = q.front();
            int curY = tmp.first;
            int curX = tmp.second;
            int setY = v[i].second.first;
            int setX = v[i].second.second;
            q.pop();
                for(int k = 0; k<4; k++){
                    int nX = offset[k][0] + curX; 
                    int nY = offset[k][1] + curY;

                    if(nX >= curX - 1 && nY >= curY - 1 && nX <= setX - 1 && nY <= setY - 1){
                        q.push({nY,nX});
                        sum += map[curY][curX];
                    }
                }
            q.pop(); 
        } 
        cout << sum << '\n';   
    }
    // visit 추가하기
}