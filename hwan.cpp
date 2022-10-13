#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char c[101][101] = {0,}, t;
    int v[101][101] = { 0, }, cnt = 0;
    int v2[101][101] = { 0, }, cnt2 = 0;
    queue<pair<int, int>> q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) {
                q.push(make_pair(i, j));
                v[i][j] = 1;
                cnt++;
                while (!q.empty()) {
                    pair<int, int> now = q.front();
                    t = c[now.first][now.second];
                    q.pop();
                    if (now.first != 0 && c[now.first - 1][now.second] == t && v[now.first - 1][now.second] == 0) {
                        q.push(make_pair(now.first - 1, now.second));
                        v[now.first - 1][now.second] = 1;
                    }
                    if (now.second != n - 1 && c[now.first][now.second + 1] == t && v[now.first][now.second + 1] == 0) {
                        q.push(make_pair(now.first, now.second + 1));
                        v[now.first][now.second + 1] = 1;
                    }
                    if (now.first != n - 1 && c[now.first + 1][now.second] == t && v[now.first + 1][now.second] == 0) {
                        q.push(make_pair(now.first + 1, now.second));
                        v[now.first + 1][now.second] = 1;
                    }
                    if (now.second != 0 && c[now.first][now.second - 1] == t && v[now.first][now.second - 1] == 0) {
                        q.push(make_pair(now.first, now.second - 1));
                        v[now.first][now.second - 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v2[i][j]) {
                q.push(make_pair(i, j));
                v2[i][j] = 1;
                cnt2++;
                if (c[i][j] == 'R' || c[i][j] == 'G') {
                    while (!q.empty()) {
                        pair<int, int> now = q.front();
                        q.pop();
                        if (c[now.first - 1][now.second] == 'R' || c[now.first - 1][now.second] == 'G') {
                            if (now.first != 0 && v2[now.first - 1][now.second] == 0) {
                                q.push(make_pair(now.first - 1, now.second));
                                v2[now.first - 1][now.second] = 1;
                            }
                        }
                        if (c[now.first][now.second + 1] == 'R' || c[now.first][now.second + 1] == 'G') {
                            if (now.second != n - 1 && v2[now.first][now.second + 1] == 0) {
                                q.push(make_pair(now.first, now.second + 1));
                                v2[now.first][now.second + 1] = 1;
                            }
                        }
                        if (c[now.first + 1][now.second] == 'R' || c[now.first + 1][now.second] == 'G') {
                            if (now.first != n - 1 && v2[now.first + 1][now.second] == 0) {
                                q.push(make_pair(now.first + 1, now.second));
                                v2[now.first + 1][now.second] = 1;
                            }
                        }
                        if (c[now.first][now.second - 1] == 'R' || c[now.first][now.second - 1] == 'G') {
                            if (now.second != 0 && v2[now.first][now.second - 1] == 0) {
                                q.push(make_pair(now.first, now.second - 1));
                                v2[now.first][now.second - 1] = 1;
                            }
                        }
                    }
                }
                else {
                    while (!q.empty()) {
                        pair<int, int> now = q.front();
                        t = c[now.first][now.second];
                        q.pop();
                        if (now.first != 0 && c[now.first - 1][now.second] == t && v2[now.first - 1][now.second] == 0) {
                            q.push(make_pair(now.first - 1, now.second));
                            v2[now.first - 1][now.second] = 1;
                        }
                        if (now.second != n - 1 && c[now.first][now.second + 1] == t && v2[now.first][now.second + 1] == 0) {
                            q.push(make_pair(now.first, now.second + 1));
                            v2[now.first][now.second + 1] = 1;
                        }
                        if (now.first != n - 1 && c[now.first + 1][now.second] == t && v2[now.first + 1][now.second] == 0) {
                            q.push(make_pair(now.first + 1, now.second));
                            v2[now.first + 1][now.second] = 1;
                        }
                        if (now.second != 0 && c[now.first][now.second - 1] == t && v2[now.first][now.second - 1] == 0) {
                            q.push(make_pair(now.first, now.second - 1));
                            v2[now.first][now.second - 1] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << " " << cnt2;
}