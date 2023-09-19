#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    int s, x, y, cnt = 0, sCnt = 0;
    int Map[201][201];
    int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool tog = false;

    vector<pair<int, pair<int, int>>> v;
    queue<pair<int, pair<int, int>>> q;

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> Map[i][j];
            if (Map[i][j] != 0) v.push_back({Map[i][j], {i, j}});
        }
    }

    cin >> s >> x >> y;

    if (s == 0){ cout << Map[x - 1][y - 1]; return 0; }

    sort(v.begin(), v.end());

    for (auto i : v){
        q.push(i);
    }

    int qSize = q.size();

    while (!q.empty()){

        pair<int, int> tmp = q.front().second;
        int temp = q.front().first;

        if (tog){
            qSize = q.size();
            tog = false;
        }

        q.pop();

        for (int i = 0; i < 4; i++){
            int nY = tmp.first + offset[i][0];
            int nX = tmp.second + offset[i][1];

            if (nY >= 0 && nY < n && nX >= 0 && nX < n){
                if (Map[nY][nX] == 0){
                    Map[nY][nX] = temp;
                    q.push({temp, {nY, nX}});
                }
            }
        }

        cnt++;

        if (cnt == qSize){
            cnt = 0;
            tog = true;
            s--;
            if (s == 0) break;
        }
    }
    cout << Map[x - 1][y - 1];
}