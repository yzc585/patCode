#include<iostream>
#include<string>
#include<set>
#include <algorithm>
using namespace std;
void start(){	
	set<char>ans;
	string goodS = "";
	string badS = "";	
	cin >> goodS >> badS;	
	for (int  i = 0; i < goodS.length(); i++)
	{
		if ((goodS[i] >= 'a' && goodS[i] <= 'z')){//  ��Сд��ĸ
			goodS[i] = toupper(goodS[i]);
		}		
	}
	for (int i = 0; i < badS.length(); i++)
	{
		if ((badS[i] >= 'a' && badS[i] <= 'z')){//  ��Сд��ĸ
			badS[i] = toupper(badS[i]);
		}
	}
	cout << goodS << "  " << badS << endl;
	for (int i = 0; i < goodS.length(); i++)
	{
		if (badS.find(goodS[i]) == badS.npos && ans.find(goodS[i]) == ans.end()){
			cout << goodS[i];
			ans.insert(goodS[i]);
		}
	}
	cout << endl;

}