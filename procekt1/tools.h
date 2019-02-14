#include<iostream>
#include<string>
#include<map>

int str_to_int(string str){
	int num=0;
	for(int i=0;i<str.size();i++){
		num*=10;
		num+=str[i]-'0';
	}
	return num;

}

int is_name(string s){
	if(s.size()==0) return false;
	for(int i=0;i<s.size();i++){
		int mark = 0;
		if(s[i]>='a' && s[i]<='z') mark = 1;
		if(s[i]>='A' && s[i]<='Z') mark = 1;
		if(s[i]>='0' && s[i]<='9' && i!=0) mark = 1;
		if(mark==0) return false;
	}
	return true;
}

int var_to_int(string var , map<string,int>& values , vector<string>variables ){

}