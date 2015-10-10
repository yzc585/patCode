#include<iostream>
#include<stdio.h>
using namespace std;
void start(){
	int n = 0;
	scanf("%d", &n);
	int tmp = 0;
	long long sum = 0;
	int count5 = 0;
	int count0 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		tmp == 5 ? count5++ : count0++;	
	}
	if (count0 == 0 ){
		printf("-1");
		return;
	}
	if (count5==0){
		printf("0");
		return;
	}
	if (count5 <= 8 ){
		printf("0");
		return;
	}		
	for (int i = 0; i < count5 - count5 % 9 ; i++)
	{
		printf("5");
	}
	for (int i = 0; i < count0; i++)
	{
		printf("0");
	}	
}