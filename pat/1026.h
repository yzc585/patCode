#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
void start(){
	int C1,C2,hour,minute,second = 0;	
	int CLK_TCK = 100;
	cin >> C1 >> C2;
	second = (C2 - C1) / 100;
	if ((C2 - C1) % 100 >= 50)second++;
	hour = second/3600;
	minute = (second - hour * 3600) / 60;
	second = second - hour * 3600 - minute * 60;
	printf("%02d:%02d:%02d\n", hour, minute, second);	
}