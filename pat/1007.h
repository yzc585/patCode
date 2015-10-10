#include<iostream>
#include<stdio.h>
using namespace std;
int getSum(int * &numbers,int startIndex,int endIndex){
    int sum=0;
    for(int i=startIndex;i<=endIndex;++i){
        sum+=numbers[i];
    }
    return sum;
}
void start()
{
    int number=0;
    cin>>number;
    int * numbers=new int[number];
    bool negative=false;
	bool positive = false;
	int allPositiveSum = 0;	
    for(int i=0;i<number;++i){
        cin>>numbers[i];
        if(numbers[i]>=0){
            negative=true;
        }
		if (numbers[i] <=0){
			positive = true;
		}		
		allPositiveSum += numbers[i];
    }
	if (!positive){// 如果都是正数 
		cout << allPositiveSum << " " << numbers[0] << " " << numbers[number - 1];
		return;
	}
    if(!negative){
        cout<<0<<" "<<numbers[0]<<" "<<numbers[number-1];
        return;
    }
    int step=0;
    int maxSum=0;
    int minIndex=0;
    int startIndex=0;
	int s = 0;
	int e = 0;
    int endIndex=0;
    int tmpSum=0;
	bool isStart = false;
    for(int i=0;i<number;++i){
		if (tmpSum>=0){
			s = i;			
			tmpSum += numbers[i];	
		}
		else{
			s = i;
			e = i;
			tmpSum = numbers[i];
		}
		if (tmpSum > maxSum  || tmpSum==0){
			maxSum = tmpSum;
			startIndex = s;
			endIndex = e;
		}
    }
    cout<<maxSum<<" "<<numbers[startIndex]<<" "<<numbers[endIndex];
}
