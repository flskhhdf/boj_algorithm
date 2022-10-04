#include "iostream"
#include <algorithm>
#include "math.h"
#include <cmath>
#include <ios>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,cen=0,range=0,num[500001],max1=0,flag,mode,ave,tem;
    double sum;
    int most[8001]={0};
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> num[i];
        sum += num[i];
        most[4000+num[i]]++;
    }

    sort(num,num+n);

    for(int i = 0; i<8001; i++){
		if(most[i] > max1){
			max1 = most[i];
			flag = i;
		}
	}

	for(int i = flag+1; i<8001; i++){
		if(most[i] == max1){
			flag = i;
			break;
		}
	}


    cen = num[(n-1)/2];
    mode = flag-4000;
    range = num[n-1] - num[0];

    ave = round(sum / n);
    
    cout << ave << '\n' << cen << '\n' << mode << '\n' << range;  

}