#include<iostream>
#include<string>
using namespace std;
long long getGongYue(long long a1, long long a2){	
	a1 = a1 >= 0 ? a1 : -a1;
	a2 = a2 >= 0 ? a2 : -a2;
	if (a1 != 0 && a2 != 0){
		long long min = a1 >= a2 ? a2 : a1;
		long long max = a1 >= a2 ? a1 : a2;
		long long gongyue = 1;
		long long b1 = max;
		long long b2 = min;
		long long temp = 1;
		while (true)//b1>b2
		{
			temp = b2;
			b2 = b1%b2;
			b1 = temp;
			if (b2 == 0){
				gongyue = b1;
				break;
			}
		}
		return gongyue;
	}
	else
	{
		return 1;
	}
}
long long getGongBei(long long a1, long long a2){
	long long gongyue = getGongYue(a1, a2);
	long long b1 = a1 / gongyue;
	long long b2 = a2 / gongyue;
	return gongyue*b1*b2;
}
void Cout(long long a1, long long a2){
	long long gongyue = getGongYue(a1, a2);
	a1 = a1 / gongyue; 
	a2 = a2 / gongyue;
	if (a2 < 0){
		a2 = -a2;
		a1 = -a1;
	}
	if (a1==0)
	{
		cout << "0";
		return;
	}
	if (a2==1)
	{
		if (a1 > 0)
		{
			cout << a1;
			return;
		}
		else
		{
			cout << "(" << a1 << ")";
			return;
		}
	}
	if (a1 < 0){
		if (-a1>a2){
			a1 = -a1;
			cout << "(-"<< a1/a2 <<" "<<a1%a2<< "/" << a2<<")";
		}
		else{
			cout << "(" <<a1 << "/" << a2 << ")";
		}
		
	}
	else
	{
		if (a1 > a2){
			cout <<  a1 / a2 << " " << a1%a2 << "/" << a2 ;
		}
		else
		{
			cout << a1 << "/" << a2;
		}
		
	}	
}
void plusAndMinus(long long a1, long long a2, long long b1, long long b2){
	long long fenmu = 0;
	long long fenzi = 0;
	long long a =1;
	long long b = 1;
	Cout(a1, a2);
	cout << " + ";
	Cout(b1, b2);
	cout << " = " ;
	if (a1 == 0){
		a = 0;
	}	
	if (b1 == 0)
	{
		b = 0;
	}
	if (a == 0 && b == 0){
		cout << 0;
		cout << endl;
	}else
	if (a != 0 && b == 0){
		Cout(a1, a2);
		cout << endl;
	}else
	if (a == 0 && b != 0){
		Cout(b1, b2);
		cout << endl;
	}
	else{
		fenmu = getGongBei(a2, b2);
		fenzi = a1*fenmu / a2 + b1*fenmu / b2;
		long long gongyue = getGongYue(fenmu, fenzi);
		fenmu = fenmu / gongyue;
		fenzi = fenzi / gongyue;
		Cout(fenzi, fenmu);
		cout << endl;
	}
	a = 1;
	b = 1;
	//------
	Cout(a1, a2);
	cout << " - ";
	Cout(b1, b2);
	cout << " = ";
	if (a1 == 0){
		a = 0;
	}
	if (b1 == 0)
	{
		b = 0;
	}
	if (a == 0 && b == 0){
		cout << 0;
		cout << endl;
	}
	else
	if (a != 0 && b == 0){
		Cout(a1, a2);
		cout << endl;
	}
	else
	if (a == 0 && b != 0){
		Cout(-b1, b2);
		cout << endl;
	}
	else{
		fenmu = getGongBei(a2, b2);
		fenzi = a1*fenmu / a2 - b1*fenmu / b2;
		long long gongyue = getGongYue(fenmu, fenzi);
		fenmu = fenmu / gongyue;
		fenzi = fenzi / gongyue;
		Cout(fenzi, fenmu);
		cout << endl;
	}	
}
void multy(long long a1, long long a2, long long b1, long long b2){
	if (a1==0)
	{
		Cout(a1, a2);
		cout << " * ";
		Cout(b1, b2);
		cout << " = "<<0<<endl;
		return;
	}
	if (b1 == 0)
	{
		Cout(a1, a2);
		cout << " * ";
		Cout(b1, b2);
		cout << " = " << 0 << endl;
		return;
	}
	Cout(a1, a2);
	cout << " * ";
	Cout(b1, b2);
	cout << " = ";
	long long a = getGongYue(a2, b1);
	long long b = getGongYue(a1, b2);
	a1 = a1 / b;
	a2 = a2 / a;
	b1 = b1 / a;
	b2 = b2 / b;
	long long fenmu = a2*b2;
	long long fenzi = a1*b1;
	Cout(fenzi, fenmu);
	cout << endl;
}
void divide(long long a1, long long a2, long long b1, long long b2){
	if (a1 == 0)
	{
		Cout(a1, a2);
		cout << " / ";
		Cout(b1, b2);
		cout << " = " << 0 << endl;
		return;
	}
	if (b1 == 0)
	{
		Cout(a1, a2);
		cout << " / ";
		Cout(b1, b2);
		cout << " = " << "Inf" << endl;
		return;
	}
	Cout(a1, a2);
	cout << " / ";
	Cout(b1, b2);
	cout << " = ";
	long long a = getGongYue(a1, b1);
	long long b = getGongYue(a2, b2);
	a1 = a1 / a;
	a2 = a2 / b;
	b1 = b1 / a;
	b2 = b2 / b;
	long long fenmu = a2*b1;
	long long fenzi = a1*b2;
	Cout(fenzi, fenmu);
	cout << endl;
}
void yunSuan(long long a1, long long a2, long long b1, long long b2){
	//+
	long long gongyue_a = getGongYue(a1, a2);
	a1 = a1 / gongyue_a;
	a2 = a2 / gongyue_a;
	long long gongyue_b = getGongYue(a1, a2);
	b1 = b1 / gongyue_b;
	b2 = b2 / gongyue_b;
	long long fenmu = 0;
	long long fenzi = 0;
	plusAndMinus(a1, a2, b1, b2);	
	multy(a1, a2, b1, b2);
	divide(a1, a2, b1, b2);		
}
void start(){
	long long a1=0, a2=0, b1=0, b2 = 0;	
	scanf_s("%lld/%lld %lld/%lld", &a1, &a2, &b1, &b2);	
	cout<<getGongYue(a1, a2);
	//yunSuan(a1, a2, b1, b2);	
}