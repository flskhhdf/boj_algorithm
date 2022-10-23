#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m, map[50][50] = {0}, dir, box;
int tmp[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
vector<pair<int, int>> cloud;

void cloudmove(int a, int b) {
    int dis = b % n, ndis = n - b % n;
	int cloudsize = cloud.size();
    if (a == 1) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >= dis)
                cloud[i].second -= dis;
            else
                cloud[i].second += ndis;
        }
    } else if (a == 2) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >= dis)
                cloud[i].second -= dis;
            else
                cloud[i].second += ndis;
            if (cloud[i].first >= dis)
                cloud[i].first -= dis;
            else
                cloud[i].first += ndis;
        }
    } else if (a == 3) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].first >= dis)
                cloud[i].first -= dis;
            else
                cloud[i].first += ndis;
        }
    } else if (a == 4) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].first >= dis)
                cloud[i].first -= dis;
            else
                cloud[i].first += ndis;
            if (cloud[i].second >= ndis)
                cloud[i].second -= ndis;
            else
                cloud[i].second += dis;
        }
    } else if (a == 5) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >= ndis)
                cloud[i].second -= ndis;
            else
                cloud[i].second += dis;
        }
    } else if (a == 6) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >= ndis)
                cloud[i].second -= ndis;
            else
                cloud[i].second += dis;
            if (cloud[i].first >= ndis)
                cloud[i].first -= ndis;
            else
                cloud[i].first += dis;
        }
    } else if (a == 7) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].first >= ndis)
                cloud[i].first -= ndis;
            else
                cloud[i].first += dis;
        }
    } else {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >= dis)
                cloud[i].second -= dis;
            else
                cloud[i].second += ndis;
            if (cloud[i].first >= ndis)
                cloud[i].first -= ndis;
            else
                cloud[i].first += dis;
        }
    }
}

void addwater() {
    int offset[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
	int cloudsize = cloud.size();
    for (int i = 0; i < cloudsize; i++) {
        map[cloud[i].first][cloud[i].second]++;
    }

    for (int i = 0; i < cloudsize; i++) {
        int cnt = 0;
        pair<int, int> tmp = cloud[i];
        for (int j = 0; j < 4; j++) {
            int nY = tmp.first + offset[j][0];
            int nX = tmp.second + offset[j][1];
            if (nX < n && nX >= 0 and nY < n && nY >= 0){
				if(map[nY][nX] != 0) cnt++;
			} 
        }
        map[cloud[i].first][cloud[i].second] += cnt;
    }

    vector<pair<int, int>> ncloud;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] >= 2) {
                ncloud.push_back({i, j});
                map[i][j] -= 2;
                for (int k = 0; k < cloudsize; k++) {
                    if (i == cloud[k].first && j == cloud[k].second) {
                        map[i][j] += 2;
                        ncloud.pop_back();
                    }
                }
            }
        }
    }

	while(!cloud.empty()){
		cloud.pop_back();
	}

	int ncsize = ncloud.size();

    for (int i = 0; i < ncsize; i++) {
		cloud.push_back(ncloud[i]);
    }

}

int main() {

    cin >> n >> m;

    cloud.push_back({n - 1, 0});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 2, 0});
    cloud.push_back({n - 2, 1});

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
	
    for (int i = 0; i < m; i++) {
        cin >> dir >> box;
        cloudmove(dir, box);
			for(int j = 0; j<cloud.size(); j++){
				// cout << cloud[j].first << ' ' << cloud[j].second << '\n';
				
			}
        addwater();
	}
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += map[i][j];
        }
    }
    cout << sum;
    return 0;
}