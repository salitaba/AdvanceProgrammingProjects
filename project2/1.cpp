#include<iostream>
#include<vector>
#include<string>
using namespace std;
void createQueue(string& s,int& index,char pre='?'){
	if(index == s.size())
		return;
	if(pre != s[index]){
		cout<<s[index];
	}
	index++;
	createQueue(s,index,s[index-1]);
}
int main(){
	string str;
	cin>>str;
	int index=0;
	createQueue(str,index);
	return 0;
}