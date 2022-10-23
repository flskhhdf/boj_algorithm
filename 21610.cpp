#include "iostream"
#include "vector"
#include "stack"
using namespace std;
int n,m,map[50][50]={0},dir,box;
vector<pair<int,int>> cloud;
int offset[4][2] = {{-1,-1},{-1,1},{1,1},{1,-1}};

void rain(){
	for(int k = 0; k<cloud.size(); k++){
		map[cloud[k].first][cloud[k].second]++;
	}
	for(int i = 0; i<cloud.size(); i++){
		int cnt = 0;
		pair<int,int> tmp = cloud[i];
		for(int j = 0; j<4; j++){
			int nY = tmp.first + offset[j][0];
			int nX = tmp.second + offset[j][1];
			if(nY >= 0 && nY < n && nX >= 0 && nX < n){
				if(map[nY][nX] != 0) cnt++;
			}
		}
		map[tmp.first][tmp.second] += cnt; 
	}
}

void makeCloud(){
	vector<pair<int,int>> v;
	
	int tmp = cloud.size();

	for(int i = tmp; i>0; i--){
		v.push_back(cloud[i-1]);
		cloud.pop_back();
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(map[i][j] >= 2) {
				cloud.push_back({i,j});
				map[i][j] -= 2;
				for(int k = 0; k<v.size(); k++){
					if(i == v[k].first && j == v[k].second) {map[i][j]+=2; cloud.pop_back();}
				}
			}
		}
	}



}

void cloudmove(int a, int b) {
    int dis = b % n, ndis = n - b % n,cloudsize=cloud.size();
    
   if (a == 1) {
      for (int i=0; i<cloudsize; i++) {
            if (cloud[i].second >=dis) cloud[i].second-=dis;
            else cloud[i].second+=ndis;
      }
   }   
   else if (a == 2) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >=dis) cloud[i].second-=dis;
            else
                cloud[i].second += ndis;
            if (cloud[i].first >= dis) cloud[i].first-=dis;
            else cloud[i].first+=ndis;
      }
   }   
   else if (a == 3) {
      for (int i=0; i<cloudsize; i++) {
            if (cloud[i].first >= dis) cloud[i].first-=dis;
            else cloud[i].first+=ndis;
      }
    }
   else if (a == 4) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].first >= dis) cloud[i].first-=dis;
            else
                cloud[i].first += ndis;
            if (cloud[i].second >= ndis) cloud[i].second-=ndis;
            else cloud[i].second+=dis;
      }
    }
   else if (a == 5) {
      for (int i=0; i<cloudsize; i++) {
            if (cloud[i].second >= ndis) cloud[i].second-=ndis;
            else cloud[i].second+=dis;
      }
   }
   else if (a == 6) {
        for (int i = 0; i < cloudsize; i++) {
            if (cloud[i].second >= ndis) cloud[i].second-=ndis;
            else
                cloud[i].second += dis;
            if (cloud[i].first >= ndis)   cloud[i].first-=ndis;
            else cloud[i].first+=dis;
      }
    }
   else if (a == 7) {
        for (int i=0; i<cloudsize; i++) {
            if (cloud[i].first >= ndis)   cloud[i].first-=ndis;
            else cloud[i].first+=dis;
      }
    }
   else {
        for (int i=0; i<cloudsize; i++) {
         if (cloud[i].second >=dis) cloud[i].second-=dis;
         else
                cloud[i].second += ndis;
            if (cloud[i].first >= ndis)   cloud[i].first-=ndis;
            else cloud[i].first+=dis;
      }
   }
}

// void cloudMove(int d, int m){
// 	int rep = cloud.size();
// 	while(m--){
// 		if(d == 1) {
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].second - 1 < 0){
// 					cloud[i].second = n-1;
// 				}
// 				else cloud[i].second -= 1;
// 			}	
// 		}
// 		else if(d == 2){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].first -  1 < 0 && cloud[i].first - 1 < 0){
// 					cloud[i].first = n-1; cloud[i].second = n-1;
// 				}
// 				else if (cloud[i].first - 1 < 0){
// 					cloud[i].first = n-1;
// 					cloud[i].second -= 1; 
// 				}
// 				else if (cloud[i].second - 1 < 0){
// 					cloud[i].second = n-1;
// 					cloud[i].first -= 1; 
// 				}
// 				else {
// 					cloud[i].first -= 1;
// 					cloud[i].second -= 1;
// 				}
// 			}
// 		}
// 		else if(d == 3){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].first - 1 < 0){
// 					cloud[i].first = n-1; 
// 				}
// 				else cloud[i].first -= 1;
// 			}
// 		}
// 		else if(d == 4){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].first - 1 < 0 && cloud[i].second + 1 > n-1){
// 					cloud[i].first = n-1;
// 					cloud[i].second = 0;
// 				}
// 				else if (cloud[i].first - 1 < 0){
// 					cloud[i].first = n-1;
// 					cloud[i].second += 1; 
// 				}
// 				else if (cloud[i].second + 1 > n-1){
// 					cloud[i].second = 0;
// 					cloud[i].first -= 1; 
// 				}
// 				else {
// 					cloud[i].first -= 1;
// 					cloud[i].second += 1;
// 				}
// 			}
// 		}
// 		else if(d == 5){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].second + 1 > n-1){
// 					cloud[i].second = 0;
// 				}
// 				else cloud[i].second += 1;
// 			}
// 		}
// 		else if(d == 6){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].first + 1 > n-1 && cloud[i].second + 1 > n-1){
// 					cloud[i].first = 0;
// 					cloud[i].second = 0;
// 				}  
// 				else if (cloud[i].first + 1 > n-1) {
// 					cloud[i].first = 0;
// 					cloud[i].second += 1; 
// 				}
// 				else if (cloud[i].second + 1 > n-1) {
// 					cloud[i].first += 1; 
// 					cloud[i].second = 0;
// 				}
// 				else {
// 					cloud[i].first += 1;
// 					cloud[i].second += +1;
// 				}
// 			}
// 		}
// 		else if(d == 7){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].first + 1 > n-1) cloud[i].first = 0;
// 				else cloud[i].first += 1;
// 			}
// 		}
// 		else if(d == 8){
// 			for(int i = 0; i<rep; i++){
// 				if(cloud[i].first + 1 > n-1 && cloud[i].second - 1 < 0){
// 					cloud[i].first = 0;
// 					cloud[i].second = n-1;
// 				}
// 				else if (cloud[i].first + 1 > n-1){
// 					cloud[i].first = 0;
// 					cloud[i].second -= 1;
// 				}
// 				else if (cloud[i].second - 1 < 0){
// 					cloud[i].second = n-1;
// 					cloud[i].first += 1; 
// 				}
// 				else {cloud[i].first += 1; cloud[i].second -= 1;}
// 			}
// 		}
// 	}
// }

int main(){
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0 ; j<n; j++){
			cin >> map[i][j];
		}
	}

	cloud.push_back({n-1,0});
	cloud.push_back({n-1,1});
	cloud.push_back({n-2,0});
	cloud.push_back({n-2,1});

	// for(int i = 0; i<4; i++){
	// 	cout << cloud[i].first << ' ' << cloud[i].second  << '\n';
	// }
	// cout << '\n';
	for(int i = 0; i<m; i++){
		cin >> dir >> box;
		cloudmove(dir,box);
		rain();
		makeCloud();

		// for(int j = 0; j<n; j++){
		// 	for(int k = 0; k<n; k++){
		// 		cout << map[j][k] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
	}

	// for(int i = 0; i<cloud.size(); i++){
	// 	cout << cloud[i].first << ' ' << cloud[i].second  << '\n';
	// }
	int sum = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			sum += map[i][j];
		}
	}
	cout << sum;

}