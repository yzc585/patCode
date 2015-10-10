#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct people
{
	int number;
	int de;
	int cai;
	int zong;
};
bool compare(const people &pl1,const people & pl2){	
	if (pl1.zong == pl2.zong){
		if (pl1.de == pl2.de){
			return pl1.number < pl2.number;
		}
		else{
			return pl1.de > pl2.de;
		}		
	}
	else {
		return pl1.zong > pl2.zong;
	}
	
}
void Cout(vector<people>&temp){
	for (int i = 0; i < temp.size(); i++)
	{
		printf("%d %d %d\n", temp[i].number, temp[i].de, temp[i].cai);		
	}
}
void start(){
	int count = 0;
	int L = 0;
	int H = 0;
	cin >> count >> L >> H;
	vector<people>first;
	vector<people>second;
	vector<people>third;
	vector<people>fourth;
	int M = 0;
	for (int i = 0; i < count; i++)
	{
		int number, de, cai;
		scanf("%d %d %d",&number, &de, &cai);
		people pl;
		pl.number = number;
		pl.de = de;
		pl.cai = cai;
		pl.zong = de + cai;
		if (de >= H && cai >= H){
			first.push_back(pl);
			M++;
		}
		else
		{
			if (de >= H && cai < H && cai>=L){
				second.push_back(pl);
				M++;
			}
			else{
				if (de>=L && de < H && cai < H && de >=cai && cai>=L ){
					third.push_back(pl);
					M++;
				}
				else{
					if ( de >= L && cai >= L){
						fourth.push_back(pl);
						M++;
					}
					
				}
			}
		}	
	}	
	cout << M << endl;
	sort(first.begin(), first.end(), compare);
	sort(second.begin(), second.end(),  compare);
	sort(third.begin(), third.end(),  compare);
	sort(fourth.begin(), fourth.end(),  compare);	
	Cout(first);
	Cout(second);
	Cout(third);
	Cout(fourth);
}