#include<iostream>
#include<string>
using namespace std;
void CoutNum(int num, int count){
	for (int i = 0; i < count; i++)
	{
		cout << num;
	}
}
void start(){
	int *count = new int[10];
	for (int i = 0; i < 10; ++i){
		cin >> count[i];
	}
	bool hasZero = false;
	if (count[0]>0){
		hasZero = true;
	}
	bool coutZero = false;
	for (int i = 1; i < 10; i++)
	{
		if (count[i]>0){
			if (!coutZero && hasZero){
				cout << i;
				CoutNum(0, count[0]);
				CoutNum(i, count[i] - 1);
				coutZero = true;
				continue;
			}
			else{
				CoutNum(i, count[i]);
			}
		}
	}
	cout << endl;
}