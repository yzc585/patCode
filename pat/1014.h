#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void start(){
  string str1, str2, str3, str4;
  cin >> str1 >> str2 >> str3 >> str4;
  int week = 0;
  int flag = 1;
  string weeks[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
  int hours[24] = { 0 };
  for (int i = 0; i < 24; i++)
  {
    hours[i] = i;
  }
  for (int i = 0; i < str1.length(); i++)
  {
    if (i >= str2.length()) break;
    if (str1[i] == str2[i] && str1[i]>='A' && str1[i]<='G' && flag==1){
      week = str1[i] - 'A' ;
      cout << weeks[week] << " ";
      flag = 2;
    }
    else{
      if (flag == 2 && str1[i] == str2[i] &&( ( str1[i] >= 'A' && str1[i] <= 'N')||(str1[i]>='0' && str1[i]<='9'))){
        if (str1[i] >= 'A' && str1[i] <= 'N'){
          cout << hours[str1[i] - 'A' + 10]<<":";
          break;
        }
        else{
          printf("%02d:",hours[str1[i] - '0']) ;
          break;
        }
      }

    }
  }
  for (int i = 0; i < str3.length(); i++)
  {
    if (i >= str4.length()) break;
    if (str3[i] == str4[i] && ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z'))){
      printf("%02d\n", i);
      break;
    }
  }

}
