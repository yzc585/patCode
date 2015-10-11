#include<iostream>
using namespace std;
int Max(int a[], int n){
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[max]<a[i]){
			max = i;
		}
	}
	return max;
}
void Swap( int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void Print( int a[],int n){
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
void SelectSort(int a[],int n){
	for (int i = n-1; i >0; i--)
	{
		int max = Max(a, i);
		Swap(a[max], a[i]);		
	}
}

int main(){
	int a[] = { 2, 5, 1, 9, 8, 7 };
	SelectSort(a,6);
	Print(a,6);
	system("pause");
	return 0;
}