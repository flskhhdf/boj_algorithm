#include "iostream"
#include "algorithm"
#include <vector>
using namespace std;

vector<pair<int,int>> a, b, c,res;
pair<int,pair<int, int>> p[1001];
int n;

bool check(int idx, int which){
	pair<int,int> tmp;
	if(which == 1) { 
		tmp = a[idx-3];
		for(int i = 0; i<a.size()-1; i++){

		}
	} 
	else if(which == 2) { tmp = b[idx-3];} 
	else if(which == 3) { tmp = c[idx-3];}

	if(p[idx].second.first > tmp.first) {
		if(p[idx].second.first >= tmp.second){
			if(which == 1) a.push_back(p[idx].second);
			else if(which == 2) b.push_back(p[idx].second);
			else if(which == 3) c.push_back(p[idx].second);
			return 1;
		}
	}
	else if (p[idx].second.first < tmp.first) {
		if(p[idx].second.second <= tmp.first){
			if(which == 1) a.push_back(p[idx].second);
			else if(which == 2) b.push_back(p[idx].second);
			else if(which == 3) c.push_back(p[idx].second);
			return 1;
		}
	}
	return 0;
}


int main(){
	cin >> n;
	
	for(int i = 0; i<n; i++){
		cin >> p[i].second.first >> p[i].second.second;
		p[i].first = abs(p[i].second.first - p[i].second.second); 	
	}
	
	sort(p,p+n);

	a.push_back({p[0].second.first,p[0].second.second});
	b.push_back({p[1].second.first,p[1].second.second});
	c.push_back({p[2].second.first,p[2].second.second});

	for(int i = 0; i<n; i++){
		cout << p[i].second.first << ' ' << p[i].second.second << ' ' << p[i].first << '\n';
	}
	cout << '\n';
	for(int i = 3; i<n; i++){
		if(check(i,1)) {continue;}
		else if (check(i,2)) { continue;}
		else if (check(i,3)) {continue;}
	}

	for(int i = 0; i<a.size(); i++){
		cout << a[i].first << ' ' << a[i].second << '\n';
	}
	cout << '\n';
	for(int i = 0; i<b.size(); i++){
		cout << b[i].first << ' ' << b[i].second << '\n';
	}
	cout << '\n';
	for(int i = 0; i<c.size(); i++){
		cout << c[i].first << ' ' << c[i].second << '\n';
	}
}