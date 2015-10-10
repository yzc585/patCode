#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void start(){
	int N = 0;
	cin >> N;
	int *grades = new int[N];
	memset(grades, 0, sizeof(int));
	int num = 0;
	int grade = 0;
	for (int i = 0; i < N; ++i){
		cin >> num;
		cin >> grade;
		grades[num - 1] = grades[num - 1] + grade;
	}
	int max = 0;
	int flag = 0;
	for (int i = 0; i < N; ++i){
		if (max < grades[i]){
			max = grades[i];
			flag = i + 1;
		}
			
	}
	cout << flag << " " << max;

}