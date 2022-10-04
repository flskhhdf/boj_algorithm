#include "iostream"
#include "vector"
using namespace std;

int main(){
	vector<int> v;
	int k,n[6],m[6],Wmax=0,Vmax=0,area=1,save;

	cin >> k;

	for(int i = 0; i<6; i++){
		cin >> n[i] >> m[i];
		if(n[i] == 1 || n[i] == 2){
			if(m[i]>Wmax) Wmax = m[i];
		}
		else if(n[i] == 3 || n[i] == 4){
			if(m[i]>Vmax) Vmax = m[i];
		}
	}                 

	for(int i = 0; i<6; i++){
		if(i==5) v.push_back(m[0]*m[5]);
		else v.push_back(m[i]*m[i+1]);
	}                 

	
	int i=0;

	while(1){
		if(v[i] == Wmax*Vmax){
			save = (i+3)%6;
			break;
		}
		i++;
	}
	cout << area*k << '\n';
	area = (Wmax * Vmax)-v[save];
}