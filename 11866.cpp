#include "iostream"
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 1; i<=n; i++){
        arr[i] = i;
    }
    int point=k,cnt=0;
    for(int i = 0; i<n; i++){ 
        cout << arr[point] << ' ';
        arr[point] = 0; // 죽은것은
        point += k;

        if(point>n){
            point -= n;
        }

        
        if(arr[point] == 0){
            cnt++;
        }

    }
}

// n = 7  1 2 3 4 5 6 7
// k = 3           // 1 2 3 4 5 6 7
// 3번 죽고 1번은 4 // 1 2 0 4 5 6 7
// 6번 죽고 1번은 7 // 1 2 0 4 5 0 7
// 2번 죽고 1번은 4 // 1 0 0 4 5 0 7
// 7번 죽고 1번은 1 // 1 0 0 4 5 0 0
// 5번 죽고 1번은 1 // 1 0 0 4 0 0 0
// 1번 죽고 1번은 4 // 0 0 0 4 0 0 0
// 4번 죽음         // 0 0 0 0 0 0 0