#include "iostream"
#include <utility>
#include "limits.h"
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m,k,Dpos,Ddir,xPos,yPos,dir,cnt[2]={0},sum=0,min=INT_MAX; 
	cin >> n >> m >> k;
	
	pair<int, int> p[101];

	for(int i = 0; i<k; i++){

		cin >> p[i].first >> p[i].second;
		
		if(p[i].first == 1) {p[i].first = p[i].second, p[i].second = 0;}
		else if(p[i].first == 2) {p[i].first = p[i].second, p[i].second = m;}
		else if(p[i].first == 3) {p[i].second = p[i].first-1, p[i].first = 0;}
		else if(p[i].first == 4) {p[i].second = p[i].first, p[i].first = n;}
	}

	cin >> Ddir >> Dpos;

	for(int i = 0; i<k; i++){
		for(int j = 0; j<2; j++){
			cnt[j] = 0;

			if(Ddir == 1) {
				yPos = 0, xPos = Dpos;
				if(j == 0) dir = 4; 
				else if (j == 1) dir = 3;
			}

			else if (Ddir == 2) {
				yPos = m, xPos = Dpos;
				if(j == 0) dir = 3;
				else if (j == 1) dir = 4;
			}

			else if (Ddir == 3) {
				yPos = Dpos, xPos = 0;
				if(j == 0) dir = 1; 
				else if (j == 1) dir = 2;
			}

			else if (Ddir == 4) {
				yPos = Dpos, xPos = n;
				if(j == 0) dir = 2; 
				else if(j == 1) dir = 1;
			}

			while(1){
				if(dir == 1){
					if(yPos > 0) {yPos--,cnt[j]++;}
					else if((yPos == 0) && (xPos == 0)) dir = 4;
					else if((yPos == 0) && (xPos == n)) dir = 3;		
				}

				else if(dir == 2){
					if(yPos < m) {yPos++,cnt[j]++;}
					else if ((yPos == m) && (xPos == 0)) dir = 4;
					else if ((yPos == m) && (xPos == n)) dir = 3;
				}

				else if(dir == 3){
					if(xPos > 0) {xPos--, cnt[j]++;}
					else if ((xPos == 0) && (yPos == 0)) dir = 2;
					else if ((xPos == 0) && (yPos == m)) dir = 1;
				}

				else if(dir == 4){
					if(xPos < n) {xPos++, cnt[j]++;}
					else if ((xPos == n) && (yPos == 0)) dir = 2;
					else if ((xPos == n) && (yPos == m)) dir = 1;
				}

				if(p[i].first == xPos && p[i].second == yPos){
					break;
				}
			}				
			if(cnt[j] < min) min = cnt[j];
		}
		sum += min;
	}
	cout << sum;
}