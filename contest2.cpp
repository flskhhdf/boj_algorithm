#include<iostream>
using namespace std;
int main() {
	int N, array[500000];
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> array[i];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(array[i] > array[j]) {
				int temp;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		cout << array[i] << ' ';
	}
}