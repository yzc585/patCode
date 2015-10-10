#include<iostream>
#include<string>
using namespace std;
void start(){
	char *bad1 = new char[10000];
	string bad = "";
	string txt = "";
	gets(bad1);	
	cin >> txt;
	bool capLock = false;
	if (bad1[0]=='\0'){
		cout << txt;
		return;
	}
	bad = bad1;
	if (bad.find('+',0)!=bad.npos)
	{
		capLock = true;
	}
	for (int i = 0; i< txt.length(); ++i){
		if (capLock && (txt[i] >= 'A'&& txt[i] <= 'Z')){
			txt=txt.replace(i,1,"");
			--i;
			continue;
		}
		if (txt[i] >= 'a' && txt[i]<='z' && bad.find(toupper(txt[i]),0) != bad.npos){
			txt = txt.replace(i, 1, "");
			--i;
			continue;
		}
		if (bad.find(txt[i],0) != bad.npos ){
			txt = txt.replace(i, 1, "");
			--i;
			continue;
		}	
		
	}	
	if (txt.length() == 0){
		cout << "\n";
	}else
		cout << txt << endl;
}