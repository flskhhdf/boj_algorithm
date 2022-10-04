#include "iostream"
#include <ios>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		ios_base::sync_with_stdio(0);
		// 상1 우2 하3 좌4
		int yPos=0,xPos=0,dir=1,i=0,xMax=0,xMin=0,yMax=0,yMin=0;
		string move;

		cin >> move;

		// for(int i = 0; i<move.size(); i++){
		// 	cout << move[i] << ' ';
		// }

		while(i != move.size()){
			if(move[i] == 'L'){
				if(dir == 1) dir = 4;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 2; 
				else if (dir == 4) dir = 3;
			}

			else if(move[i] == 'R'){
				if(dir == 1) dir = 2;
				else if (dir == 2) dir = 3;
				else if (dir == 3) dir = 4; 
				else if (dir == 4) dir = 1;
			}

			if(dir == 1){
				if(move[i] == 'F') yPos++;
				else if (move[i] == 'B') yPos--;
			}

			else if (dir == 2){
				if(move[i] == 'F') xPos++;
				else if (move[i] == 'B') xPos--;
			}

			else if (dir == 3){
				if(move[i] == 'F') yPos--;
				else if (move[i] == 'B') yPos++; 
			}

			else if (dir == 4){
				if(move[i] == 'F') xPos--;
				else if (move[i] == 'B') xPos++;
			}
			i++;
			// cout << "X : " << xPos << ' ' << "Y : " << yPos << '\n';
			if(xPos > xMax) xMax = xPos;
			if(xPos < xMin) xMin = xPos;
			if(yPos > yMax) yMax = yPos;
			if(yPos < yMin) yMin = yPos;
		}
		// cout << xMax << ' ' << xMin << ' ' << yMax << ' ' << yMin <<'\n';
		cout << (xMax - xMin) * (yMax - yMin) << '\n';
	}
}