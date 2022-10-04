#include <iostream>
using namespace std;

int main()
{
   float max = 0;
   float sum=0;
   float avr = 0;
   int n;
   cin >> n;
   int arr[100] ={};
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
      if (arr[i] > max)
         max = arr[i]; //최댓값
   }
   
   for (int i = 0; i < n; i++)
   {
      sum += arr[i] / max * 100;
      avr = sum / n;
   }
   cout << avr;
   
}