#include "iostream"
using namespace std;

int main(){
    int arr[1000];
    int idx=1;
    int temp = 0;
    int sum=0;
    int a,b;
    cin >> a >> b;
    for(int i = 1; i<=b; i++){
        for(int j = 0; j<i; j++){
            arr[temp] = idx;
            if(temp > 1000) break;
            temp++;
        }
        idx++;
    }
    for(int i=a-1; i<b; i++) sum += arr[i];
    cout << sum;
}

// #include "iostream"
// using namespace std;

// int main(){
//     int arr[1000];
//     int idx=2;
//     int temp = 1;
//     int sum=0;
//     int a,b;
//     cin >> a >> b;
//     arr[0] = 1;
//     for(int i = 2; i<=b; i++){
//         for(int j = 0; j<i; j++){
//             arr[temp] = idx;
//             arr[temp] = arr[temp]+arr[temp-1];
//             if(temp>1000) break;
//             temp++;
//         }
//         idx++;
//     }
//     if(a==1) cout << arr[b-1];
//     else {
//         sum = arr[b-1] - arr[a-2];
//         cout << sum;
//     }
// }

// #include "iostream"
// using namespace std;

// int main(){
//     int arr[1001];
//     int temp = 1;
//     int sum=0;
//     int a,b;
//     for(int i = 1; i<=1000; i++){
//         for(int j = 1; j<=i; j++){
//             arr[temp] = i;
//             // if(temp>1000) break;
//             temp++;
//         }
//     }
//     cin >> a >> b;
// 	for(int i=a; i<=b; i++){
// 		sum+=arr[i];
// 	}
//     cout << sum;
// }

// #include <iostream>

// using namespace std;
// int main(){
// 	int arr[1001],n,m,ans=0,k=1;
// 	for(int i=1; i<=1000; i++){
// 		for(int j=1; j<=i; j++){
// 			arr[k]=i;
// 			if(k>1000){
// 				break;
// 			}
// 			k++;
// 		}
// 	}
// 	cin>>n>>m;
// 	for(int i=n; i<=m; i++){
// 		ans+=arr[i];
// 	}
// 	cout<<ans;
// }

// 1   2   3   4   5   6   7   8   9   10
// 0   1   2   3   4   5   6   7   8   9 
// 1   2   2   3   3   3   4   4   4   4
// 1   3   5   8   11  14  18  22  26  30
