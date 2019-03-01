#include<iostream>
#include<vector>
#include<string>
using namespace std;
void createQueue(string& str,int index=0,char pre='?'){
	if(index == str.size())
		return;
	if(pre != str[index]){
		cout<<str[index];
	}
	index++;
	createQueue(str,index,str[index-1]);
}
int main(){
	string str;
	cin>>str;
	createQueue(str);
	return 0;
}