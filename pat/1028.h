#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
class people
{	
public:
	people(string name,int year,int month,int day);
	people(){}
	~people();
	string name;
	int year;
	int month;
	int day;

};

people::people(string name, int year, int month, int day)
{
	this->name = name;
	this->month = month;
	this->year = year;
	this->day = day;
}

people::~people()
{	
}
void copy(people &p1, people &p2){
	p1.name = p2.name;
	p1.month = p2.month;
	p1.year = p2.year;
	p1.day = p2.day;
}
void getOlder(people &older,people &temp){
	if (older.year < temp.year){ copy(older, temp); return; }
	if (older.year == temp.year && older.month < temp.month){ copy(older, temp); return; }
	if (older.year == temp.year && older.month == temp.month && older.day <= temp.day){ copy(older, temp); return; }
}

void getYounger(people &yonger, people &temp){
	if (yonger.year > temp.year){ copy(yonger, temp); return; }
	if (yonger.year == temp.year && yonger.month > temp.month){ copy(yonger, temp); return; }
	if (yonger.year == temp.year && yonger.month == temp.month && yonger.day >= temp.day){ copy(yonger, temp); return; }
}
void start(){
	string name = "";
	int year = 0;
	int month = 0;
	int day = 0;
	int N = 0;
	scanf("%d", &N);
	int count = 0;
	people oldest("temp", 1814, 9, 6);
	people youngest("temp", 2014, 9, 6);
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		scanf("%d/%d/%d",&year, &month, &day);
		if (year == 2014){
			if (month == 9){
				if (day>6){ continue; }
			}
			else{
				if (month > 9){ continue; }
			}
		}
		else{
			if (year > 2014){ continue; }
		}
		if (year == 1814){
			if (month == 9){
				if (day<6){ continue; }
			}
			else{
				if (month < 9){ continue; }
			}
		}
		else{
			if (year < 1814){ continue; }
		}
		people pl(name, year, month, day);
		getOlder(oldest, pl);
		getYounger(youngest, pl);	
		count++;
		//cout << name << year << month << day;
	}
	if (count == 0){ cout << 0<<endl; return; }
	cout << count << " "<<youngest.name<<" "<<oldest.name<<endl;
}