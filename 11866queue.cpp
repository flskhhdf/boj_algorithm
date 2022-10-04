#include "iostream"
#include "queue"
using namespace std;
queue<int> q;
int main(){
    int n,k;
    int num[1001];
    cin >> n >> k;
    int temp;
    for(int i = 0; i <n; i++){
        num[i] = i+1;
        q.push(num[i]);
    }
    cout << '<';
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            if(j==k-1) {
                cout << q.front();
                if(i != n-1)cout << ", ";
                q.pop();
                break;
                }
            temp =  q.front();
            q.pop();
            q.push(temp);
        }
    }
    cout << '>';
}