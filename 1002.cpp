#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int x1,y1,x2,y2,r1,r2,diff = 0,sum = 0;
        double dist = 0;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        sum = r1+r2;
        diff = abs(r1-r2);

        dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

        if (dist == 0 && r1 == r2){ cout << -1 << '\n'; }
        else if(diff < dist && dist < sum){ cout << 2 << '\n'; }
        else if (dist == sum || dist == diff){ cout << 1 << '\n'; }
        else { cout << 0 << '\n'; }
    }
}