#include "iostream"
#include "algorithm"
#include <vector>
using namespace std;

vector<pair<int,int>> a, b, c;
pair<int,pair<int, int>> p[1001];
int n;

int check(vector<pair<int,int>> v, int idx){
	pair<int,int> tmp = v[idx-3]; 
	if(p[idx].second.first > tmp.first) {if(p[idx].second.first >= tmp.second) return 1;}
	else if (p[idx].second.first < tmp.first) {if(p[idx].second.second <= tmp.first) return 2;}
	return 0;
}

void push(){
	if()
}

int main(){
	cin >> n;
	
	for(int i = 0; i<n; i++){
		cin >> p[i].second.first >> p[i].second.second;
		p[i].first = abs(p[i].second.first - p[i].second.second); // first 에는 시간을 빼서 가장 적게 걸리는 시간
		// second에는 pair로 first는 시작 시간 second는 종료 시간 p[i].second.first 는 시작시간 이런식으로
	}
	sort(p,p+n);
	a.push_back({p[0].second.first,p[0].second.second});
	b.push_back({p[1].second.first,p[1].second.second});
	c.push_back({p[2].second.first,p[2].second.second});
	// 벡터를 세 개 만들어서 일단 처음 세 개는 무조건 하나씩 넣어 주고
	// 이제 반복문 돌려서 check 함수로 들어갈 수 있는지 봐 주고 
	// push 함수로 넣어줄건데

	// for(int i = 0; i<n; i++){
	// 	cout << p[i].second.first << ' ' << p[i].second.second << ' ' << p[i].first << '\n';
	// }
	for(int i = 3; i<n; i++){
		int ac = check(a,i);
		int bc = check(b,i);
		int cc = check(c,i);
		if(ac != 0){
			if(ac == 1){

			}
			else if (ac == 2){

			}
		}
		else if(bc != 0){
			if(bc == 1)
			else if (bc == 2)
		}
		else if(cc != 0){
			if(cc == 1)
			else if (cc == 2)
		}
	}

}