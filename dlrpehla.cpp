#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 5, b = 3, c = 12;
    int t1, t2, t3;
    
    t1 = a && b;
    t2 = a || b;
    t3 = !c;

    printf("%d %d %d %d", t1 + t2 + t3, t1, t2, t3);
        
    return 0;
}

// #include <iostream>
// using namespace std;

// int main(){
//     int arr[2][3] = {1,2,3,4,5,6};
//     int (*p)[3] = NULL;
//     p=arr;
//     for(int i = 0; i<2; i++){
//         for(int j = 0; j<3; j++){
//             cout << p[i][j] << '\n';
//         }
//     }
//     cout << *(p[1]);
//     // cout << (*p)+1;
// }