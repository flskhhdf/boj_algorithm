#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<string> maps){
    vector<int> answer;
    queue<pair<int, int>> q;
    int offset[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visit[100][100] = {0};
    int sum = 0;

    for (int i = 0; i < maps.size(); i++){
        for (int j = 0; j < maps.size(); j++){
            if (maps[i][j] != 'X')
            {
                q.push({i, j});
                while (!q.empty())
                {

                    pair<int, int> tmp = q.front();
                    q.pop();

                    if (!visit[tmp.first][tmp.second])
                        continue;

                    for (int i = 0; i < 4; i++)
                    {
                        int nY = tmp.first + offset[i][0];
                        int nX = tmp.second + offset[i][1];
                        if (nY >= 0 && nY < maps.size() && nX >= 0 && nX < maps.size())
                        {
                            if (!visit[nY][nX])
                            {
                                q.push({nY, nX});
                            }
                        }
                    }
                }
            }
        }
    }

    return answer;
}