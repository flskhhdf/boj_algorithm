#include "iostream"
#include <vector>
using namespace std;
int n, map[500][500], dir = 1;
bool visit[500][500];

void movePos() {
    // 왼쪽 1 아래 2 오른쪽 3 위 4
    int xPos = n / 2, yPos = n / 2;

    visit[yPos][xPos] = 1;
    while (xPos != -1 && yPos != -1) {

        if (dir == 1) {
            while (dir != 2) {
                cout << xPos << ' ' << yPos << '\n';
                visit[yPos][xPos] = 1;
                xPos--;
                if (visit[yPos + 1][xPos] == 0) dir = 2;
            }
        }

        else if (dir == 2) {
            while (dir != 3) {
                cout << xPos << ' ' << yPos << '\n';
                visit[yPos][xPos] = 1;
                yPos++;
                if (visit[yPos][xPos + 1] == 0) dir = 3;
            }
        }

        else if (dir == 3) {
            while (dir != 4) {
                cout << xPos << ' ' << yPos << '\n';
                visit[yPos][xPos] = 1;
                xPos++;
                if (visit[yPos - 1][xPos] == 0) dir = 4;
            }
        }

        else if (dir == 4) {
            while (dir != 1) {
                cout << xPos << ' ' << yPos << '\n';
                visit[yPos][xPos] = 1;
                yPos--;
                if (visit[yPos][xPos - 1] == 0) dir = 1;
            }
        }
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    movePos();

    // for(int i = 0; i<n; i++){
    // 	for(int j = 0; j<n; j++){
    // 		cout << visit[i][j] << ' ';
    // 	}
    // 	cout << '\n';
    // }
}