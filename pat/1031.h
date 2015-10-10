#include<iostream>
#include<string>
using namespace std;
void start(){
	int N = 0;
	cin >> N;
	string *id = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> id[i];
	}
	int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int sum = 0;
	int sum_weight = 0;
	string flags="10X98765432";
	for (int i = 0; i < 17; ++i){ sum_weight += weight[i]; }
	bool zimuFlag = false;
	bool noError = false;
	for (int  i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < 17; ++j)
		{
			if (id[i][j] >= '0' && id[i][j] <= '9')
			{
				sum += (id[i][j]-'0') * (weight[j]);
				continue;
			}
			else
			{
				zimuFlag = true;				
				break;
			}
		}
		if (zimuFlag){// 如果前17位有字母
			cout << id[i] << endl;
			zimuFlag = false;
			noError = true;			
			continue;
		}
		char jiaoyan = flags[(sum ) %11];
		if (jiaoyan != id[i][17])
		{
			cout << id[i] << endl;			
			noError = true;
		}
	}
	if (!noError){
		cout << "All passed" << endl;
	}
}