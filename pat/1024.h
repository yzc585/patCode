#include<iostream>
#include<string>
using namespace std;
void start(){
	string sample = "";
	cin >> sample;
	bool positive = true;
	if (sample[0] == '-'){
		positive = false;
	}
	int intPart = sample[1]-'0';
	int  xsPart = 0;
	bool exFlag = true;
	int exPart = 0;
	int exStart = 0;
	for (int  i = 3; i < sample.length(); i++)
	{
		if (sample[i] == 'E'){
			xsPart = i - 3;//  小数位数
			exStart = 1;//  开始计算指数大小
			if (sample[i + 1] == '-'){
				exFlag = false;				
								
			}
			i++;
			continue;
		}
		if (exStart == 1){
			exPart = exPart * 10 + (sample[i] - '0');
		}
	}
	int size = 0;
	if (exFlag){
		if (exPart > xsPart){
			size = size + exPart-1;
		}
		else{
			size = size + xsPart;
		}
		size += 2;
	}
	else{
		size = size + xsPart + exPart+2;
	}
	char * result = new char[size+1];
	if (!positive){
		cout << "-";
	}
	bool meetE = false;
	int position = 3;
	for (int  i = 0; i < size; i++)
	{		
		if (exFlag){
			if (i == 0){
				result[i] = intPart + '0';
				continue;
			}
			else{
				if (xsPart < exPart){//  小数部分小于指数
					if (!meetE){// 没有遇到E						
						if (sample[i + 2] == 'E'){
							meetE = true;
							result[i] = '0';
							continue;
						}
						result[i] = sample[i + 2];
					}
					else
					{
						result[i] = '0';
					}
				}
				else{
					if (i <= exPart){
						result[i] = sample[i + 2];
					}
					else
					{
						if (i == exPart + 1){
							result[i] = '.';
						}
						else{
							result[i] = sample[i + 1];
						}
					}
				}	
			}
		}
		else{
			if (i < 2){
				result[0] = '0';
				result[1] = '.';
			}			
			if (i>=2 && i <= exPart){
				result[i] = '0';
				continue;
			}
			if (i == exPart+1){
				result[i] = intPart+'0';
				continue;
			}
			if (i > exPart + 1){
				result[i] = sample[position];
				position++;
				continue;
			}
		}
	}
	bool meetDot = false;
	bool hasCout = false;
	for (int  i = 0; i < size; i++)
	{
		if (!meetDot && result[i] == '0' && result[i + 1] == '0' && !hasCout){
			continue;
		}
		if (result[i + 1] == '.'){
			meetDot = true;
		}
		if (result[i + 1] != '.' && result[i] == '0' && !hasCout){
			continue;
		}
		if (result[i] == '.' && i == size - 1){
			continue;
		}
		cout << result[i];
		hasCout = true;
	}cout << endl;
	cout << positive << "--" << intPart << "--" << xsPart << "---" << exFlag << "--" << exPart << endl;
}