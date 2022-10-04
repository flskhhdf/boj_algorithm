#include <iostream>
#include <string>
using namespace std;

int main()
{
   int tc;
   cin >> tc;
   
   for(int i = 0; i<tc; i++){
	float arr[1000]={};
	float s;
	float sum = 0;
	float avr = 0;
	int cnt = 0;

		cin >> s;
		for (int j = 0; j < s; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}
		avr = sum / s;
		for (int j = 0; j < s; j++)
		{
			if (avr < arr[j])
				cnt++;
		}
		cout.precision(3);
		cout << fixed;
		cout << (cnt/ s) *100 << "%\n";
   }

}

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
	
//    int tc;
//    cin >> tc;
//    float arr[1000]={};
//    float s;
//    float avr = 0;
//    for (int i = 0; i < tc; i++)
//    {
//    	  float sum = 0;
//    	  int cnt = 0;
//       cin >> s;
//       for (int j = 0; j < s; j++)
//       {
//          cin >> arr[j];
//          sum += arr[j];
//       }
//       avr = sum / s;
//       for (int j = 0; j < s; j++)
//       {
//          if (avr < arr[j])
//             cnt++;
//       }
// 	//   cout << cnt/s << '\n';
//       cout.precision(3);
//       cout << fixed;
//       cout << (cnt/s) *100 << "%\n";
//    }

// }

// int n;
// 	float cnt=0, sum=0, ave=0;
// 	int num[1000];
// 	cin >> n;
// 	for(int i = 0; i<n; i++){
// 		cin >> num[i];
// 		sum += num[i];
// 	}
// 	ave = sum/n;

// 	cout << ave << '\n';

// 	for(int i = 0; i<n; i++){
// 		if(ave < num[i]) cnt++;
// 	}
// 	cout << cnt << '\n';

// 	cout << (float)(cnt/n)*100;
