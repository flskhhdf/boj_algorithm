#include "vector"
#include <deque>
#include <iostream>
#include <string.h>
using namespace std;
vector<deque<int>> dq(5);
bool visit[5];      //방문 확인
int decide_dir[5]; //회전시킬 방향 저장

void check_rotate(int w, int d) { //톱니번호(0,1,2,3)
    visit[w] = 1;
    decide_dir[w] = d;

    if (w - 1 > 0 && visit[w - 1] == 0) { //왼쪽
        if (d == 0) check_rotate(w - 1, 0);
        else if (dq[w][6] != dq[w - 1][2]) check_rotate(w - 1, -d);
        else check_rotate(w - 1, 0);
    }

    if (w + 1 <= 4 && visit[w + 1] == 0) { //오른쪽
        if (d == 0)
            check_rotate(w + 1, 0);
        else if (dq[w][2] != dq[w + 1][6])
            check_rotate(w + 1, -d);
        else
            check_rotate(w + 1, 0);
    }
}

void rotating() {
    for (int i = 1; i <= 4; i++) {
        if (decide_dir[i] == -1) { //반시계
            int tmp = dq[i].front();
            dq[i].pop_front();
            dq[i].push_back(tmp);
        } else if (decide_dir[i] == 1) { //시계
            int tmp = dq[i].back();
            dq[i].pop_back();
            dq[i].push_front(tmp);
        } else if (decide_dir[i] == 0)
            continue; //회전 x
    }
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int k, wheel_n, direct1,sum = 0; //회전 횟수, 톱니바퀴 번호, 방향(0, 1, -1), 점수 합
    char str;
    for (int i = 1; i < 5 ; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> str;
            dq[i].push_back(str - '0'); //입력값 숫자로 변환 후 deque에 저장
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> wheel_n >> direct1; //돌릴 톱니바퀴 번호와 방향 입력
        memset(visit, 0, sizeof(visit)); //초기화
        check_rotate(wheel_n, direct1);
        rotating();
    }
    if (dq[1][0] == 1) sum += 1;
    if (dq[2][0] == 1) sum += 2;
    if (dq[3][0] == 1) sum += 4;
    if (dq[4][0] == 1) sum += 8;

    cout << sum;
}
