#include <algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
struct record
{
	char name[21];
	char dateTime[12];
	bool online;
	bool cal;
};
struct  pairRd
{
	record first;
	record second;
};
bool isSmaller(char dt1[], char dt2[]){
	for (int i = 0; i < strlen(dt1); i++)
	{
		if (dt1[i]>dt2[i]){
			return false;
		}
		if (dt1[i] < dt2[i]){
			return true;
		}
	}
	return false;
}
bool isClose(record rd,int r, int j, record rds[],int size){
	record tmp = rds[j];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(rds[i].name, rd.name) && i != j && i != r){
			
			if ( ((isSmaller(rd.dateTime, rds[i].dateTime) && isSmaller(rds[i].dateTime, tmp.dateTime)) || (isSmaller(tmp.dateTime,rds[i].dateTime ) && isSmaller(rds[i].dateTime, rd.dateTime)))){
				return false;
			}
		}		
	}
	
	return true;
}
bool sortRecord(pairRd p1,pairRd p2){
	if (strcmp(p1.first.name, p2.first.name) > 0){
		return false;
	}
	else{
		if (strcmp(p1.first.name, p2.first.name) < 0){
			return true;
		}
		else{
			if (strcmp(p1.first.dateTime, p2.first.dateTime) > 0){
				return false;
			}
			else{
				return true;
			}
		}
	}	
}
int calTime(char t1[],char t2[]){
	int day = (t2[3] - t1[3])*10 + t2[4] - t1[4];
	int hour = (t2[6] - t1[6])*10 + t2[7] - t1[7];
	int minute = (t2[9] - t1[9])*10 + t2[10] - t1[10];
	day = day * 60 * 24;
	hour = hour * 60;
	return day + minute + hour;
}
float getMoney(char t1[], char t2[], float toll[]){	
	float moneyDay = 0.0,moneyHour=0.0,moneyMinute=0.0,money=0.0;
	for (int i = 0; i < 24; i++)
	{
		moneyDay += toll[i];
	}
	moneyDay = moneyDay * 60  / 100;
	int dayStart = (t1[3] - '0') * 10+t1[4]-'0';
	int dayEnd = (t2[3] - '0') * 10 + t2[4] - '0';	
	int hourStart = t1[7] - '0' + (t1[6] - '0') * 10;
	int hourEnd = t2[7] - '0' + (t2[6] - '0') * 10;
	int minuteStart=(t1[9] - '0') * 10 + t1[10]-'0';
	int minuteEnd = (t2[9] - '0') * 10 + t2[10]-'0';
	if (dayStart == dayEnd){
		if (hourStart == hourEnd){
			money = toll[hourStart] * (minuteEnd - minuteStart) / 100;
		}
		else{
			float period = 60 - minuteStart;
			money = money + period * toll[hourStart] / 100;
			for (int i = 1; i <hourEnd - hourStart; i++)
			{
				money = money + 60 * toll[hourStart + i] / 100;
			}
			money = money + minuteEnd * toll[hourEnd] / 100;
		}
	}
	else{
		int period = 60 - minuteStart;
		money = money + period * toll[hourStart] / 100;
		for (int i = 1; i <24 - hourStart; i++)
		{
			money = money + 60 * toll[hourStart + i] / 100;
		}
		for (int i = 1; i < dayEnd-dayStart; i++)
		{
			money = money + moneyDay;
		}
		for (int i = 0; i < hourEnd; i++)
		{
			money = money + 60 * toll[i] / 100;
		}
		money = money + minuteEnd * toll[hourEnd] / 100;
	}
	return money;
}
void start(){
	float toll[24];
	memset(toll, sizeof(float), 0);
	for (int i = 0; i < 24; i++)
	{
		scanf("%f", &toll[i]);		
	}
	int recordCount = 0;
	scanf("%d", &recordCount);	
	record *rds = new record[recordCount];
	for (int i = 0; i < recordCount; i++)
	{
		char name[21],dateTime[12],online[9];
		scanf("%s %s %s", name, dateTime, online);
		record rd;
		strcpy(rd.name, name);		
		strcpy(rd.dateTime, dateTime);
		char tmp[9] = "on-line";
		rd.online = (!strcmp(online,tmp)) ? true : false;
		rd.cal = false;
		rds[i] = rd;
	}
	vector<pairRd> prds;
	for (int i = 0; i < recordCount; i++)
	{
		record tmpRd = rds[i];
		if (!tmpRd.cal){
			for (int j = 0; j < recordCount; j++)
			{
				if ( !strcmp(tmpRd.name,rds[j].name) && !rds[j].cal && tmpRd.online && !rds[j].online && isSmaller(tmpRd.dateTime, rds[j].dateTime)&& isClose(tmpRd,i,j,rds,recordCount) ){
					tmpRd.cal = true;
					rds[j].cal = true;
					pairRd prd;					
					prd.first = tmpRd;
					prd.second = rds[j];
					prds.push_back(prd);
				}
			}
		}		
	}
	sort(prds.begin(),prds.end(),sortRecord);
	/*for (int i = 0; i < prds.size(); i++)
	{
		printf("%s %s %d--", prds[i].first.name, prds[i].first.dateTime, prds[i].first.online);
		printf("%s %s %d\n", prds[i].second.name, prds[i].second.dateTime, prds[i].second.online);
	}*/
	for (int i = 0; i < prds.size(); i++)
	{
		char name[21], dateTime1[12], dateTime2[12];
		record rd = prds[i].first, second;
		strcpy(name, rd.name);
		printf("%s %c%c\n", name, rd.dateTime[0], rd.dateTime[1]);
		float money = 0.0;
		for (int j = i; j < prds.size(); ++j){
			record first = prds[j].first;
			record second = prds[j].second;
			for (int n = 3; n < strlen(first.dateTime); n++)
			{
				printf("%c", first.dateTime[n]);
			}
			printf(" ");
			for (int n = 3; n < strlen(second.dateTime); n++)
			{
				printf("%c", second.dateTime[n]);
			}
			printf(" ");
			int times = calTime(first.dateTime, second.dateTime);
			printf("%d ", times);
			float tmpMoney = getMoney(first.dateTime, second.dateTime, toll);
			printf("$%.02f\n", tmpMoney);
			money = money + tmpMoney;
			if (j + 1 < prds.size() && strcmp(name, prds[j + 1].first.name)){
				break;
			}
			i++;
		}
		printf("Total amount: $%.02f\n", money);
	}
	

}