#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
void Print(int line, char fu,int n){
	for (int i = 0; i < n-line; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 2*line-1; i++)
	{
		cout << fu;
	}
	cout << endl;
}
void start(){
	int N = 0;	
	char fu = ' ';
	scanf("%d %c", &N, &fu);
	int n = sqrt((N + 1) / 2);
	for (int  i = n; i >= 1; i--)
	{
		Print( i,fu,n);
	}
	for (int i = 2; i <= n; i++)
	{
		Print(i, fu, n);
	}
	cout << N - 2*n*n+1<<endl;
	//cout << n<<"  "<<fu;

}