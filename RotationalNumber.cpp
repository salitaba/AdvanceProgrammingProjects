#include<bits/stdc++.h>
using namespace std;
const int mx=10;
int mark[mx];
int main(){
	string s;cin>>s;
	int num=1;
	while(s!="0"){
		int cnt=0;
		for(int i=0;i<s.size();i++) mark[i]=0;
		int index=0;
		while(mark[index]==0){
			cnt++;
			mark[index]=1;
			index=(s[index]-'0'+index)%s.size();
		}
		cout<<"Case "<<num<<": ";
		if(cnt==s.size() && index==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		num++;
		cin>>s;
	}
	return 0;
}

		

