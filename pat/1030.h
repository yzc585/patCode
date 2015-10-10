#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
void start(){
	int N = 0;
	cin >> N;
	long long p = 0;
	long long temp = 0;
	cin >> p;
	vector<long long>shu;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		shu.push_back(temp);
	}
	sort(shu.begin(), shu.end());
	int size = 0;
	int left = 0;
	int right = 0;		
	while (left<N && right<N)
	{
		while (right<N &&left<N && shu[right] <= shu[left] * p)
		{
			size = max(size, (right - left + 1));			
			right++;
		}
		left++;
	}
	cout << size << endl;

}