#include<bits/stdc++.h>
using namespace std;
const int mx=2e5;
string s[mx];
int main(){
	int r,c;cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>s[i];
	}
	for(int j=0;j<c;j++){
		int pre=r-1;
		for(int i=r-1;i>=0;i--){
			if(s[i][j]=='#') pre=i-1;
			else if(s[i][j]=='a'){
				s[i][j]='.';
				s[pre][j]='a';
				pre--;
			}
		}
	}
	for(int i=0;i<r;i++){
		cout<<s[i]<<endl;
	}
}
