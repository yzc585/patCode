#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int getInt(char t){
	if (t >= 'a'){
		return t - 'a' + 10;
	}
	else{
		return t - '0';
	}
}
long long int convertToInt(char *n1, long long int n){
	long long int result = 0;	
	for (int i = 0; i <strlen(n1); i++)
	{
		long long int tmp = 0;
		if (n1[i] >= 'a'){
			tmp = n1[i]-'a'+10;
		}
		else{
			tmp = n1[i] - '0';
		}		
		result = result * n+ tmp ;
		if (result < 0){
			return -1;
		}
	}
	return result;
}
long long int getMinRadix(char *n){
	char max = '0';
	for (int i = 0; i <strlen(n); ++i){
		if (n[i] > max){
			max = n[i];
		}
	}
	if (max <= '9'){
		return max - '0';
	}
	return max - 'a' + 10;
}
void start(){
	char N1[15] , N2[15] ;
	int tag = 1;
	long long int radix = 0;
	scanf("%s %s %d %lld", N1, N2, &tag, &radix);	
	long long int  minRadix = 0,maxRadix=0;
	if (tag == 2){	
		char tmp[15];
		strcpy(tmp, N1);
		strcpy(N1, N2);
		strcpy(N2, tmp);		
	}
	long long int valueN1 = convertToInt(N1, radix);
	minRadix = getMinRadix(N2)+1;
	if (strlen(N2) == 1 && getInt(N2[0]) == valueN1){
		printf("%lld", minRadix);
		return;
	}
	maxRadix = valueN1 + 1;
	long long int ans = 0;
	while (minRadix<=maxRadix)
	{
		ans = (maxRadix + minRadix) / 2;
		long long int tmpN2 = convertToInt(N2, ans);
		if (tmpN2 == -1 || tmpN2 > valueN1){
			maxRadix = ans - 1;
		}
		else if (tmpN2<valueN1)
		{
			minRadix = ans + 1;
		}
		else if (tmpN2 == valueN1){
			printf("%lld", ans);
			return;
		}		
	}
	cout << "Impossible";
	return;	
}