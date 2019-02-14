#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
		cout<<"String #"<<i<<endl;
        for(int j=0;j<s.size();j++){
            if(s[j]=='Z'){
				s[j]='A';
			}else{
				s[j]++;
			}
		}
		cout<<s<<endl<<endl;
	}
	return 0;

            
}
