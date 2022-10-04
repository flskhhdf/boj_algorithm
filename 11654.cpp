#include "stdio.h"

int main(){
	int arr[100], N, sum = 0;
	char num[100]; 
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%c",&num[i]);
		sum+=num[i];
	}

	for(int i=0;i<N;i++){
		printf("%c\n",num[i]);
	}
	// int로 받으면 10987654321이 수를
	// 10,987,654,321 라는 수로 읽어버려서 안돼요
	// 1+0+9+8+7+6+5+4+3+2+1 을 해야하잖아요

}
