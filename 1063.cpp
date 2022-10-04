#include "iostream"
#include "math.h"
#include <algorithm>
#include <ios>
using namespace std;

int main(){
	string s,k,move,lsp,lkp;
	int n,map[8][8];
	pair<int, int> sp,kp;

	cin >> k >> s >> n;
	
	kp.first = k[0] - 65;
	kp.second = abs(k[1]-'0'- 8);

	sp.first = s[0] - 65;
	sp.second = abs(s[1] -'0'- 8);

	// cout << kp.first << ' ' << kp.second << '\n';
	// cout << sp.first << ' ' << sp.second << '\n';
	// cout << "============================\n";

	for(int i = 0; i<n; i++){

		cin >> move;

		if(move == "R"){
			if(kp.first + 1 < 8) {
				if(kp.first+1 == sp.first && kp.second == sp.second) {
					if(sp.first + 1 < 8) {
						sp.first += 1;
						kp.first += 1;
					}
				}
				else kp.first += 1;
			}
		}

		else if(move == "L"){
			if(kp.first-1>=0){
				if(kp.first - 1 == sp.first && kp.second == sp.second){
					if(sp.first-1 >= 0) {
						sp.first -= 1;
						kp.first -= 1;
					}
				}
				else kp.first -= 1;
			}
		}
		
		else if(move == "B"){
			if(kp.second+1<8){
				if(kp.first == sp.first && kp.second + 1 == sp.second){
					if(sp.second + 1 < 8) {
						sp.second += 1;
						kp.second += 1;
					}
				}
				else kp.second += 1;
			}
		}

		else if(move == "T"){
			if(kp.second-1>=0){
				if(kp.first == sp.first && kp.second - 1 == sp.second){
					if(sp.second - 1 >= 0) {
						sp.second -= 1;
						kp.second -= 1;
					}
				}
				else kp.second -= 1;
			}
		}

		else if(move == "RT"){
			if(kp.second - 1 >= 0 && kp.first + 1 < 8){
				if(kp.first + 1 == sp.first && kp.second - 1 == sp.second){
					if(sp.second - 1 >= 0 && sp.first + 1 < 8){
						sp.second -= 1;
						sp.first += 1;
						kp.second -= 1;
						kp.first += 1;
					}
				}
				else {
					kp.second -= 1;
					kp.first += 1;
				}
			}
		}

		else if(move == "LT"){
			if(kp.first - 1 >= 0 && kp.second - 1 >= 0){
				if(kp.first - 1 == sp.first && kp.second - 1 == sp.second){
					if(sp.first - 1 >= 0 && sp.second - 1 >= 0){
						sp.first -= 1;
						sp.second -= 1;
						kp.first -= 1;
						kp.second -= 1;
					}
				}
				else {
					kp.first -= 1;
					kp.second -= 1;
				}
			}
		}

		else if(move == "RB"){
			if(kp.first + 1 < 8 && kp.second + 1 < 8){
				if(kp.first + 1 == sp.first && kp.second + 1 == sp.second){
					if(sp.first + 1 < 8 && sp.second + 1 < 8){
						sp.first += 1;
						sp.second += 1;
						kp.first += 1;
						kp.second += 1;
					}
				}
				else {
					kp.first += 1;
					kp.second += 1;
				}
			}
		}

		else if(move == "LB"){
			if(kp.first - 1 >= 0 && kp.second + 1 < 8){
				if(kp.first - 1 == sp.first && kp.second + 1 == sp.second){
					if(sp.first - 1 >= 0 && sp.second + 1 < 8){
						sp.first -= 1;
						sp.second += 1;
						kp.first -= 1;
						kp.second += 1;
					}
				}
				else {
					kp.first -= 1;
					kp.second += 1;
				}
			}
		}
		// cout << "킹 : "<< kp.first << ' ' << kp.second << '\n';		
		// cout << "돌 : "<< sp.first << ' ' << sp.second << '\n';
		// cout << "================================\n";
	}

	// cout << kp.first << ' ' << kp.second << '\n';		
	// cout << sp.first << ' ' << sp.second << '\n';

	lkp = kp.first + 65;
	lsp = sp.first + 65;

	cout << lkp[0] << abs(kp.second - 8) << '\n' << lsp[0] << abs(sp.second - 8);

}